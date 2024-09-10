# Engineering Documentation - Team Violet 
![Team Violet](https://github.com/user-attachments/assets/9c2fd371-100e-4b94-a8dc-27d999703344)
## Introduction
In this repository you will find all the information related to the construction and assembly of the autonomous robot built by _Team Violet_ for the Future Engineers category in the 2024 Season.
This has been an incredible journey with a lot of obstacles, and we have done our best to come up with a design that we were not only satisfied with, but one that could properly acomplish all of the objectives present in this edition of the "Future Engineers" category.

## Contents
- Team Violet's Members
- Hardware Design
   - Design Process
   - Assembly Process
   - Elements
     - 3D Printed
     - Electronics
- Software Design
   - Image and Color Processing
     - Image Capturing
     - Creating Red and Green masks
     - Gray Image with red and green details
     - Color Detection
     - Location Processing and distance from the cones
   - Robot Movement
     - Smart Robot Servo configuration
     - Robot Orientation
     - Route Determination
   - Data Sending
 - Team History
     - 2023 Season
     - Early 2024 Season

# Team Violet's Members
 - Adrian Alvarez:
>Hi, my name is Adrian Alvarez, I'm part of Team Violet 1 and I'm responsible for the 3D designs used in the robot. My expectations of this competition are to learn and to test my skills in robotics.
 - Reinaldo Belmonte:
>My name is Reinaldo Belmonte. I am the team's programmer and I'm responsible for developing most (if not all) of the robot's moveset. My expectations for this season is to do my best with this project and, hopefully, end up in the first places.
 - Jose Zambrano:
>I am José Miguel Zambrano, the team's mechanic. I am in charge of the robot's assembly and its proper maintenance. For this season I hope, alongside my team, to deliver a project that meets the expectations, in addition to representing my institution and my country.


# Hardware Design
## Design Process
The robot is composed by a combination of 3D Printed parts for the most of its structure, the front wheels from a recicled toy car, the back wheels from a REV Robotics kit, and the electronics that give the robot its functionality.

Aditionally, the robot went through a multitude of changes until it reached its final iteration.
One of these changes was the replacement of the traditional DC motor that we used before with a «Hex Motor» , which provided a greater torque to the rear-wheel drive. 

![image](https://github.com/user-attachments/assets/0dac3444-2c79-42ad-b58b-0bf60825ca2d)

As a result, the wheels used for the rear-wheel drive had to be also replaced, since the old ones couldn't adapt to the torque provided by the Hex Motor. This way we could take advantage of all the potential the Hex Motor had to offer.

![image](https://github.com/user-attachments/assets/dee2f8aa-c0ef-4d8a-adb3-142177d8cf87)

Alongside the rear-wheel drive, we also made changes to the turning system, replacing the old Servomotor with a «Smart Robot Servo» , allowing for better and more precise turns when meeting a corner.

![image](https://github.com/user-attachments/assets/9e2f925c-0d77-45f9-8e84-642a902e337c)

Another of these changes was the reorganization of its elements, given the changes in the motors used and the space they now occupied, we made a redistribution to most of the elements present in the robot, this time taking into account to make it even more accessible for repairs or adjustments to any of its parts.

![image](https://github.com/user-attachments/assets/0fe8e963-e1b2-4f1c-b8f5-545ab305a66a)

The final design of the robot is intended as a modular design, consisting of 3 modules: lower «traction» module, middle «sensor processing» module, and upper «power supply and color processing» module. This makes it easier to make repairs on any of the modules or to replace or rearrange parts.

![image](https://github.com/user-attachments/assets/d1e977a4-3c6f-47d1-8bdc-23a5092dba35)

With all these changes made, a 3D design* for the entire structure of the robot was made, thus facilitating its visualization and analysis.

## Assembly Process
Firstly, you take the 3D Printed Chassis piece, and 

## Elements
### 3D Printed
> [!NOTE]
> All of these pieces are printed in PLA plastic, with a thickness of 0.2mm and a filler level of between 20 to 50% (depends on the piece).

- **Main Chassis**: It's the piece that contains and supports all the components found in the robot.

![image](https://github.com/user-attachments/assets/b81aa906-a63b-4fe4-9255-b5b3adb6d075)

- **Hex Motor Support Bracket**: A piece that helps fasten the Hex Motor to the Main Chassis structure.
  
![image](https://github.com/user-attachments/assets/930afabf-1804-49f6-a522-d513d7ad3582)

- **Smart Robot Servo Support Bracket**: A piece that helps fasten the Servo Motor to the Main Chassis structure.

![image](https://github.com/user-attachments/assets/ab34e9ed-d605-45a0-844f-3614b6d185ce)

- **HC-SR04 Support Bracket**: Located in the "Bumper" piece, it serves as support for the HC-SR04 ultrasonic sensor, allowing it to function properly.
  
![image](https://github.com/user-attachments/assets/6b7f4685-7113-492e-8147-6c18940981ec)

- **Bumper**: Used as a extension of the Main Chassis piece, it is used to locate the HC-SR04 sensors a little further ahead so it can detect the walls more easily.
  
![image](https://github.com/user-attachments/assets/ff2e8614-e6ad-4338-be8c-9bc7ed80cfd6)

- **Crossing System**: As it's name says, this part makes it possible to transmit the movement of the servomotor to the front wheels, thus allowing the robot to change direction.
  
![image](https://github.com/user-attachments/assets/208face9-06aa-460a-b625-3d1684cf0339)

### Electronics
  -  **L298N Motor Driver**: Located in the middle module, it is used to control the Hex Motor and the Smart Robot Servo.

![image](https://github.com/user-attachments/assets/b318fc25-9c9b-4ae0-9318-8244021ce670)

> [!IMPORTANT]
> Specifications
>- Channels: 2 (supports 2 DC motors or 1 PAP motor)
>- Logic voltage: 5V.
>- Operating Voltage: 5V-35V.
>- Current consumption (Digital): 0 to 36mA.
>- Current capacity: 2A (peaks up to 3A).
>- Maximum power: 25W.
>- Weight: 30g.

  -  **Hex Motor**: Located in the lower module of the robot, this motor serves a rear wheel drive for the robot, providing the foward or backward motion of the robot.

![Team Violet (6)](https://github.com/user-attachments/assets/f643b8b0-68ef-45e7-9512-1cbdf85f33a8)
> [!IMPORTANT]
>Specifications
>- Output Shaft: 5mm Female Hex
>- Weight: 7 oz
>- Voltage: 12V DC
>- Free Speed: 125 RPM
>- Stall Torque: 3.2 N-m
>- Stall Current: 4.4 A
>- Gear Ratio: 72:1
>- Encoder Counts per Revolution
>- At the motor: 4 counts/revolution
>- At the output: 288 counts/revolution

  -   **Smart Robot Servo**: Located alongside the Hex Motor, it gives the robot the ability to rotate the front wheels, changing the orientation of the robot, thus allowing the robot to move freely in any direction on a flat surface.

![Team Violet (8)](https://github.com/user-attachments/assets/1c37fbf0-e2ab-433c-b394-c836614daca8)
> [!IMPORTANT]
>- Specifications
>- Weight: 2.05 oz.
>- Speed: 0.14 s/60° (at 6V)
>- Stall Torque: 13.5 kg-cm / 187.8 oz-in (at 6V)
>- Stall Current: 2A (at 6V)
>- Voltage Rating: 4.8V – 7.4V, 6V nominal
>- Input Pulse Range: 500μs – 2500μs
>- Default Angular Range: 270°
>- Maximum programmable range in angular mode: 280°
>- Gear Material: Metal
>- Spline type: 25T
>- Spline Internal Thread Size: M3
>- Spline Internal Thread Depth: 6mm

  -   **Arduino Mega 2560 Wifi R3**: The MEGA2560 Wifi is a variant of the Arduino Mega programmable board that includes an ESP8266 Wifi chip. Located in the middle module, it is used to manage the robot's mobility alongside the L298N Motor Driver, thus allowing the robot to move freely on a flat surface.

![Team Violet (7)](https://github.com/user-attachments/assets/226f95b5-a6c6-4f5d-a20c-e399cd8f5db2)
> [!IMPORTANT]
>- Microcontroller: ATmega2560
>- Input voltage: 7-12V.
>- 54 digital Input/Output pins (14 of them are PWM outputs).
>- 16 analog inputs.
>- 256k flash memory.
>- 16Mhz clock speed.

  -   **Raspberry Pi 4**: The Raspberry Pi 4 is a single-board development board used for entry-level computing. It is located in the upper module and it has the purpose of managing the "Color Processing" section, thus allowing the robot to recognize adjacent colors and use this information advantegiously.

![Team Violet (9)](https://github.com/user-attachments/assets/28543380-10c2-4cb2-a976-c821c2f7005b)
> [!IMPORTANT]
>- Broadcom BCM2711, Quad core Cortex-A72 (ARM v8) 64-bit SoC @ 1.8GHz
>- 4GB LPDDR4-3200 SDRAM (depending on model)
>- 2.4 GHz and 5.0 GHz IEEE 802.11ac wireless, Bluetooth 5.0, BLE
>- Gigabit Ethernet
>- 2 USB 3.0 ports; 2 USB 2.0 ports.
>- 2 × micro-HDMI® ports (up to 4kp60 supported)
>- OpenGL ES 3.1, Vulkan 1.0
>- Micro-SD card slot for loading operating system and data storage
>- 5V DC via USB-C connector (minimum 3A*)
>- 5V DC via GPIO header (minimum 3A*)
>- Operating temperature: 0 – 50 degrees C ambient

   -   **HC-SR04 Ultrasonic Sensor**: The robot has 3 HC-SR04 ultrasonic sensors on the left, right and front of the "Bumper" piece, located in front of the middle module. They are used to provide orientation to the robot when moving in any environment, allowing it to detect obstacles or adjacent walls.

![Team Violet (10)](https://github.com/user-attachments/assets/37ed400c-cc16-441c-8d57-fe2773e33e6c)
> [!IMPORTANT]
>- Supply voltage: 5 Vcc
>- Working frequency: 40 KHz
>- Maximum range: 4.5 m
>- Minimum range: 2.0 cm
>- Minimum trigger pulse duration (TTL level): 10 μS.
>- Duration of the output echo pulse (TTL level): 100-25000 μS.
>- Minimum waiting time between one measurement and the start of another: 20 mS.
  
   -   **Camera**: The robot uses an Spedal MF920P Webcam to recognize the colors in the environment. It has a Full HD 1080p resolution at 30 fps, with a H.264 Video Compression and a microphone incorporated.

![Team Violet (13)](https://github.com/user-attachments/assets/a8b72dc5-9b44-46e3-9c54-b1c51643a8d0)
   
   -   **3.7V 18650 Lithium Batteries**: Used to provide power to the Hex Motor and Smart Robot Servo on the lower module, this batteries have a nominal voltage of 3.7V and a maximum voltage of 4.2V and a capacity of 3500 mAh each.

![Team Violet (12)](https://github.com/user-attachments/assets/1bf61be8-c50f-42f7-a7c1-6857a94975a1)

   -   **LDNIO 10000mAh Power Bank**: We use a LDNIO 10000mAh Power Bank to supply Raspberry Pi and the Arduino Mega with energy. It has 1 USB ports, along with a Micro-USB port for charging, with an output voltage of 5V and 2.4A.

![Team Violet (14)](https://github.com/user-attachments/assets/e7d98596-75bd-4749-b7e4-9c88faad8db4)


# Software Design
## Image and Color Processing
### Image Capturing
nan
### Creating Red and Green masks
nan
### Gray Image with red and green details
nan
### Color Detection
nan
### Location Processing and distance from the cones
nan

## Robot Movement
### Smart Robot Servo configuration
The Smart Robot Servo is set on Pin 7 of the Arduino Mega and is configured with _Servo.write_ function. The moveset of the Smart Robot Servo is defined by the distance given by the HC-SR04 sensors depending on whether the walls are near, far away or in a corner.
### Robot Orientation
The orientation of the robot is defined by the first corner, if the corner is of the rigth side it means that the direction is clockwise and 
vice versa.
### Route Determination
The determination of the routes is based on the color of the cone next to the robot. If the python code detects a color this information will be sent to the arduino and transformed into a left or right turn depending on the detected color.

## Data Sending
The information processed in the Raspberry Pi is sent to the Arduino Mega through the serial monitor with the serial library, using the _Ser.write_ function.

# Team History
## 2023 Season
This was the first season we took the challenge of the Future Engineers category, and it came with a lot of obstacles. The main issue was time; since we were also participating on _Copa Ka'i 2023_, it was a problem to get the time needed to really develop and perfect the design.


## Early 2024 Season
tatatata

--------------------------------------------------------------------------------------------------------------------------------------
Thank You. Team Violet - 2024.
======================================================================================================================================
