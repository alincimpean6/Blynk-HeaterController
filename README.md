# Blynk-HeaterController
Blynk-DoorGarageOpener
Blynk 2.0

##Introduction

This code uses Blynk 2.0 (2023) to control a heater, in my project it controls the heater in the dog`s cage. It uses Blynk library and virtual pins that controls a solid state relay connected to arduino.

The code gets an input in the BLYNK app if the heater is started or stopped. It gets a slider that defines how many minutes in a hour the heater will be turned on and also it gets as an input the time between the heater works (ex: 8:00pm to 8:00am)

You can use and modify this code as you want to satisfy your needs.

##Goals

At the end of this guide you will learn how to use blynk dashboard, how to code the Arduino board and how to use the time input in Blynk and control a heater with a solid state relay.

##Requirements

An Arduino Uno 
Arduino Ethernet Shield 
Solid state relay
Arduino IDE 
Blynk dashboard

##Step 1:

Install Arduino IDE Libraries If you are not familiar with Arduino IDE please start here: https://www.arduino.cc/en/Guide/HomePage Download and install the BLYNK app to your phone and libraries to your PC for Arduino IDE. Tutorial here: http://www.blynk.cc/getting-started/

##Step 2:

Create blynk datastreams and create the button, slider and time input in the phone app.

##Step 3:

Set-up IDE and Program In IDE, open the project downloaded from github. In IDE, Copy and Paste the "auth key", "project template" and "device name" from blynk dashboard

In IDE, go to tools - boards - "arduino uno" 
Plug FTDI into computer. 
Pick your COM port in IDE software. 
Load sketch to your arduino.
