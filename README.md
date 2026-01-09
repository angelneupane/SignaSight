# SignaSight Glove

SignaSight Glove is a wearable device for translating sign language gestures into text using an impulse-based ML model and assisting visually impaired users by detecting obstacles. Bluetooth is used for wireless communication; no mobile application is required.

## Features
- Sign language recognition using flex sensors + IMU
- Obstacle detection via ultrasonic sensor
- Vibration motor feedback for obstacle alerts

## Why we're making this project
We're making this project to showcase something that can actually be useful for people who can't communicate easily and visually impaired problems. We want to showcase this project in our school's exhibition.

## How it works
-Button can toggle between Sign language and Obstacle Detection mode.
1. Obstacle detection mode: The ultrasonic sensor motor detects obstacle and the vibration motor vibrates with intensity corresponding to the distance from the obstacle.
2. Sign language mode: The data from 5 flex sensors (each finger) and the accelerometer are sent to the ML model and it provides audio of the sign language gesture that will be heard through the speaker.

## 3D Model of project

<img width="538" height="704" alt="image" src="https://github.com/user-attachments/assets/512845ff-48b0-47d5-949b-9bf4a5446ca8" />
<img width="303" height="714" alt="image" src="https://github.com/user-attachments/assets/028a15fb-c43c-4e37-9f26-613e28d2ebd4" />
<img width="506" height="699" alt="image" src="https://github.com/user-attachments/assets/df936a5f-4759-41e6-904f-632ea443ec45" />

## Circuit Diagram

<img width="742" height="726" alt="image" src="https://github.com/user-attachments/assets/99ff2f19-604b-47bc-8ab0-36a789b445be" />

## Hardware Components
- ESP32 Dev Board (Bluetooth)
- Flex sensors (5 × 2.2″) (We will be using DIY sensors)
- MPU6050 IMU
- Ultrasonic HC-SR04
- Vibration motor
- Push button
- Glove + mounting materials
- Jumper wires
- Resistors, transistor and other components
- Speaker, Amplifier

## Bill of materials
Note: I attacted links to amazon and put the prices in USD as there are no online stores for me to get the prices from here in nepal and I'll have to buy them from physical stores.
|Product name                      |Product description                                           |Product link                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |Product unit price (USD)|Product amount|Product running total (USD)|
|----------------------------------|--------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------|--------------|---------------------------|
|ESP32 Dev Board                   |ESP32  Bluetooth dev board compatible with Arduino            |https://www.amazon.com/ESP-WROOM-32-Development-Microcontroller-Integrated-Compatible/dp/B08D5ZD528                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |8.99                    |1             |8.99                       |
|MPU6050 6DoF IMU Sensor Module    |MPU6050 accelerometer + gyro module for Arduino/ESP32         |https://www.amazon.com/GY-521-MPU-6050-Acceleration-Gyroscope-Schematic/dp/B096LKDHB1/ref=sr_1_3?dib=eyJ2IjoiMSJ9.3LE-6VmzALri1i1CcWyHphUHqgIvMheA5hRU1JtRJrbGjHj071QN20LucGBJIEps.-dVxrYaPSWnQYVLGK9qpz_wp-14wTFlz7zi8WIU5G_s&dib_tag=se&keywords=mpu6050+imu+sensor&qid=1767715914&sr=8-3                                                                                                                                                                                                                                                                                        |7.59                    |1             |16.58                      |
|HC-SR04 Ultrasonic Distance Sensor|HC-SR04 ultrasonic module for distance/obstacle detection     |https://www.amazon.com/Ultrasonic-Measuring-Transducer-ultrasonic-transducer/dp/B0F21FYMF1/ref=sr_1_1?dib=eyJ2IjoiMSJ9.BtA8K8OjBarVYIW523coy9Vczyk7zdN-Fk1mgk05lglBtkk0-l1g51JiLcKwYw4jF3H6hIJR7VrIlxY2iXJa8zJbU2uUG_oTLwHdNQaOdYvOc_Wqm3logl-N98XLZnGMB0PQ4ZDo7cd7baNQCTSgXGuothP864ZJXRSWp733U1cq6_WRPmTCpbR3Ts4wQ1Jf07OepV9A-p2swsBCBcZPerFhwjVUg4BCRDRiVEM4RlE.Z9hDI7BEw2keirzVN3GHgBlUdMkrstPzYue_wNlwaOQ&dib_tag=se&keywords=hc+sr04+ultrasonic+sensor&qid=1767719148&sr=8-1                                                                                                 |6.99                    |1             |23.57                      |
|10kOhm Resistor Pack (assorted)   |Pack of 10kOhm resistors for flex sensors and voltage dividers|https://www.amazon.com/Resistor-Tolerance-Resistors-Limiting-Certificated/dp/B08QRJBW9D/ref=sr_1_3?dib=eyJ2IjoiMSJ9.sKryXnIkpAlwhj5fSmCdrHvBgH3UuqKmrQ7bbInL7M97xBInp_m4YzG37ejAZe9uZMMhy4Jd5F_Xf5ZxBeHHoQFxHklPE6Wq5oyuGksXZMKUJeZQitMiTnCjK1mByjhQKegp7AlPETK2fxKGoAabwxpr4g5vJuTecL6yUez6fOoGO6ExAHEws6WEY7AklsWrN9FOjCDGLCZ9fCNbRX9di-8QfX3YmCteA4EnQZBUQxk.ZpSY8f034lkp15oaf79tbRXJhpReRTEB3UmjDxTQ7r8&dib_tag=se&keywords=10k%2Bresistor%2Bpack&qid=1767719224&sr=8-3&th=1                                                                                                   |5.99                    |1             |29.56                      |
|220ohm Resistors (assorted)       |Pack of 20ohm resistors for transistor base                   |https://www.amazon.com/Resistor-Tolerance-Resistors-Limiting-Certificated/dp/B08QR1STQC/ref=sr_1_1?crid=1XGMT459BLOD0&dib=eyJ2IjoiMSJ9.9MuC6yweietQHKaC7WRZjZD4Kg4z6Na32fsK6S0EAcdRl1cmAQieKqyNa-mu1iF5EdzBFB9FXGuM7EhGd5mylbADHV_bdoELj0-fW0aVJ5WbfyKYftH04qWt4Hc8zvMqeyMs_2vTODACYO12WIlTZHIdQvBr8pCdCEwY4p3loAB1igdit3iC1X0oFE33nshB6bmFyv6MhQrpPL4xn3eToHUkwwYkH0dvJFzXXoncPpc.jUJ0LXYCH8QqWnl85bY6WmwTXvb1BxXTcszG8EWNZZo&dib_tag=se&keywords=220%2Bohm%2Bresistor&qid=1767719331&refinements=p_36%3A-700&rnid=2661611011&sprefix=220%2Bohm%2Bresistor%2Caps%2C407&sr=8-1&th=1|5.99                    |1             |35.55                      |
|Vibration Motor 3.3V              |Mini vibration motor for haptic feedback                      |https://www.amazon.com/Vibration-Button-Type-Vibrating-Household-Appliances/dp/B0BVJR8LTN/ref=sr_1_2?crid=W9ILWJ4D04LF&dib=eyJ2IjoiMSJ9.CzK-xy3-9k_px7gp_QYCe3ROfmqDCSRRhSmXPI3iN8E.O453ExKnZEKXLGpSA-mAd3J5wyQIffCvQITrc-2mUek&dib_tag=se&keywords=3.3v+vibration+motor&qid=1767719575&sprefix=3.3v+vibration+motor%2Caps%2C507&sr=8-2                                                                                                                                                                                                                                            |4.99                    |1             |40.54                      |
|Jumper Wires Kit                  |male female jumper wires                                      |https://www.amazon.com/Elegoo-EL-CP-004-Multicolored-Breadboard-arduino/dp/B01EV70C78/ref=sr_1_1_sspa?dib=eyJ2IjoiMSJ9.1JTtZYzqh1JVSNxn_zOlNKR-NWs8wozhUHSlzQX8IqfJD8-RiofLr_KLWFglj-j-qCLGS49Q183GyWE-akKCHyEC_KoQ-DhclbFBYCP5fXeqFMH4VUJXhODKEumnHmtJFM6MuIS2JN0bFGOnRXS1AelksOzdEZx-tzXr-V8S9P38Mv4l0DameNyN7kfl9Ya7ClMENtmChwwcq5qEynSpJi4vz3YIHFNsVZaIJT3081E.aRRO0Ru_AlrY5hsTelg3z7TNbZ-dGly00VbyQeNbj4U&dib_tag=se&keywords=jumper+wire+kit&qid=1767878871&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1                                                                |6.98                    |1             |47.52                      |
|Speaker                           |3W 4Ohm speaker                                               |https://www.amazon.com/Diameter-Speaker-Ultra-thin-Amplifier-speaker/dp/B09YQ1S988/ref=sr_1_1?crid=T06OZVDHRRLA&dib=eyJ2IjoiMSJ9.6OPEZCPDYgJfpb67LAifiwAhi_4zPvV5BxIeTxF_BE_91Ecpzai9unn8oJxyhInBG42F72ZEHecCCWHQzFZTIlKREMSGTmRhW49Jzb7_Nndy1Dic9hrNzu0EDUvWYJ17RIGznwbZJHYFRahk1FQ75RO8caPuDRAezQO2d9HHNx5lgeRldB0RNjH_ytbj4KUCCjQzrQACq5Jfey5DARu3gT3nNKxCueaopn8fBPYs4zc.-9Uimpdv4pktfdznu3kHvHC6PvSgfJiUrpbrzBgNNXU&dib_tag=se&keywords=3+watt+4+ohm+speaker&qid=1767879395&sprefix=3+watt+4+o%2Caps%2C524&sr=8-1                                                             |5.4                     |1             |52.92                      |
|Amplifier                         |MAX98357A amplifier for the speaker                           |https://www.amazon.com/MAX98357-MAX98357A-Amplifier-Interface-Raspberry/dp/B0DPJRLMDJ/ref=pd_ci_mcx_di_int_sccai_cn_d_sccl_1_1/132-1914266-3268266?pd_rd_w=Fz0pl&content-id=amzn1.sym.751acc83-5c05-42d0-a15e-303622651e1e&pf_rd_p=751acc83-5c05-42d0-a15e-303622651e1e&pf_rd_r=1YE1RW38QXF0805A3VR7&pd_rd_wg=Ndj8x&pd_rd_r=1adf182c-7ad5-4cf2-a99d-4517501243f1&pd_rd_i=B0DPJRLMDJ&psc=1                                                                                                                                                                                          |6.88                    |1             |59.8                       |
