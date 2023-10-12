#define BLYNK_TEMPLATE_ID " "
#define BLYNK_DEVICE_NAME " "
#define BLYNK_AUTH_TOKEN " "

#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>
#include <TimeLib.h>

char auth[] = BLYNK_AUTH_TOKEN;


const int REL_HEATER = 9;

boolean heaterState = false;
unsigned long previousMillis = 0;
const unsigned long heaterDuration = 1200000;  
unsigned int heatingMinutes = 0;
unsigned int timeArray[5]; 

void setup() {

  setSyncInterval(3600);

  Blynk.begin(auth);
  
  pinMode(REL_HEATER, OUTPUT);
  digitalWrite(REL_HEATER, HIGH);
}

BLYNK_WRITE(V9)
{
  if(param.asInt() == 1)
  {
    Blynk.virtualWrite(V9,1);
    heaterState = true;
    } else {
    Blynk.virtualWrite(V9,0); 
    heaterState = false;
  }
}

BLYNK_WRITE(V0)
{
  heatingMinutes = param.asInt();
}

BLYNK_WRITE(V6) {
  TimeInputParam t(param);

  if (t.hasStartTime())
  {
    String startHour = t.getStartHour();
    timeArray[0] = startHour.toInt(); 

    String startMin = t.getStartMinute();
    timeArray[1] = startMin.toInt(); 
  }

  if (t.hasStopTime())
  {
    String stopHour = t.getStopHour();
    timeArray[2] = stopHour.toInt(); 

  }
}



void loop() {
  if (!Blynk.connected()) {
    Blynk.connect();
    Blynk.logEvent("connected");
  }
  Blynk.run();

  unsigned long currentTime = now();
  heaterLogic(currentTime);
}

BLYNK_CONNECTED() { 
  Blynk.syncVirtual(V0); 
  Blynk.syncVirtual(V6); 
}

void heaterLogic(unsigned long currentTime) {
  if (heaterState) {
    int currentHour = hour(currentTime);
    int currentMinute = minute(currentTime);

    if ((currentMinute == timeArray[1] || currentMinute == heatingMinutes) && currentHour >= timeArray[0] && currentHour <= timeArray[2]) {
      digitalWrite(REL_HEATER, (currentMinute == timeArray[1]) ? HIGH : LOW);
    }
  }
}
