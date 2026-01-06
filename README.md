# SignaSight Glove

SignaSight Glove is a wearable device for translating sign language gestures into text using an impulse-based ML model and assisting visually impaired users by detecting obstacles. Bluetooth is used for wireless communication; no mobile application is required.

## Features
- Sign language recognition using flex sensors + IMU
- Obstacle detection via ultrasonic sensor
- Vibration motor feedback for obstacle alerts
- Bluetooth Serial output for gesture text and obstacle alerts
- Simple, low-cost components accessible in Nepal or internationally

## Hardware Components
- ESP32 Dev Board (Bluetooth)
- Flex sensors (5 × 2.2″)
- MPU6050 IMU
- Ultrasonic HC-SR04
- Vibration motor
- Push button
- Li-ion battery
- Glove + mounting materials
- Jumper wires

## Software
- Arduino IDE firmware (`main.ino`)
- Edge Impulse ML model placeholder (`model.cpp` + `model.h`)
- Bluetooth Serial communication
- Sensor reading and obstacle detection logic

## Usage
1. Mount flex sensors on glove fingers.
2. Connect components according to `circuit_diagram.png`.
3. Upload `main.ino` to ESP32 via Arduino IDE.
4. Use push button to switch modes (gesture / obstacle detection).
5. Connect via Bluetooth Serial to read gesture labels and obstacle alerts.
