# Gesture-Controlled Robot for Military Applications

## Project Overview

This project demonstrates the development of a **gesture-controlled robot** designed for military applications. The robot is controlled by hand gestures using a combination of **accelerometers** and **gyroscopes**, with the control system built on an **Arduino-based platform**. This project aims to provide a reliable, intuitive, and flexible control system for unmanned ground vehicles with a range of up to **800 meters**.

The project consists of two main parts:
- **Transmitter**: The hand gesture inputs are captured and transmitted wirelessly to the robot.
- **Receiver**: The robot receives the transmitted data and moves accordingly.

## Key Features
- **Gesture Control**: The robot’s movements are controlled by real-time hand gestures using accelerometer and gyroscope data.
- **Wireless Communication**: Data transmission between the transmitter (hand gesture) and receiver (robot) is achieved using wireless communication protocols.
- **800-meter Range**: The system operates over a range of 800 meters, providing flexibility in various operational environments.
- **Arduino-based Controllers**: Both transmitter and receiver systems are based on Arduino microcontrollers for ease of implementation and customization.

## Components Used
- **Arduino Uno** (for both transmitter and receiver)
- **Accelerometer** (MPU650)
- **Gyroscope** (MPU6050)
- **NRF24L01 Wireless Module** (for communication)
- **Servo Motors** (for robot movement)
- **Power Supply** (rechargeable LIPO batteries)

## Transmitter Code

The transmitter code captures hand gestures via an accelerometer and gyroscope, then sends the data to the receiver over a wireless link. The transmitter reads the sensor data and processes it to recognize gestures like moving the hand up, down, left, or right, and then wirelessly sends the corresponding commands to the receiver.

### Instructions for the Transmitter Code:
1. Connect the accelerometer and gyroscope to the **Arduino Uno**.
2. Upload the transmitter code (available in this repository) to the Arduino Uno.
3. Power on the system and calibrate the sensors for accurate gesture recognition.

## Receiver Code

The receiver code processes the received wireless signals from the transmitter and uses the data to control the movement of the robot. Based on the received gesture data, the robot moves forward, backward, or turns left or right using servo motors or wheels.

### Instructions for the Receiver Code:
1. Connect the **Arduino Uno** to the motors and wireless receiver module.
2. Upload the receiver code (available in this repository) to the Arduino Uno.
3. Ensure the receiver is powered on and within range of the transmitter to receive the control signals.

## Project Report

A detailed report of the project, including design decisions, implementation steps, and challenges faced during development, is available in this repository.

### Report Contents:
- Introduction and objectives
- System design and architecture
- Components used and circuit diagrams
- Testing and results
- Conclusion and future work

## Installation and Setup

1. Clone the repository to your local machine using:
   ```bash
   git clone https://github.com/your-username/gesture-controlled-robot.git
