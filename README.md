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
     - Servomotor setting
     - Lane Determination
     - Robot Orientation
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
>I am José Miguel Zambrano, the team's mechanic, I am in charge of the robot's assembly and its proper maintenance. For this season I hope, alongside my team, to deliver a project that meets the expectations, in addition to representing my institution and my country.


# Hardware Design
## Design Process
The final design of the robot is intended as a modular design, consisting of 3 modules: lower "traction" module, middle "electronics" module, and upper "power supply and color processing" module.

The robot went through a multitude of changes until it reached its final iteration.
One of these changes was the replacement of the traditional DC motor that we used before with a Hex Motor, which had a greater strength to the wheels. 

Same thing with the turning system, being the original servomotor replaced with a more efficient and precise model at the moment of the turns.

Another of these changes was the reorganization of its elements, given the changes in the motors used and the space they now occupied, we made a redistribution to most of the elements present in the robot, this time taking into account to make it even more accessible for repairs or adjustments to any of its parts.

With all these changes made, a 3D design* for the entire structure of the robot was made, thus facilitating its visualization and analysis.

## Assembly Process
Firstly, you take the 3D Printed Chassis piece, and 

## Elements
### 3D Printed
> [!NOTE]
> All of these pieces are printed in PLA plastic, with a thickness of 0.2mm and a filler level of between 20 to 50% (depends on the piece).

- **Main Chassis**: It's the piece that contains and supports all the components found in the robot.

![5080268763353427355](https://github.com/user-attachments/assets/10351e4e-c0ce-4e54-90fb-9f68c6334554)
- **Hex Motor Support Bracket**: A piece that helps fasten the Hex Motor to the Main Chassis structure.
  
![Team Violet (3)](https://github.com/user-attachments/assets/d5ca7c77-ba7e-4c99-9dd5-d163b2e5dd29)
- **Smart Robot Servo Support Bracket**: A piece that helps fasten the Servo Motor to the Main Chassis structure.

![Team Violet (4)](https://github.com/user-attachments/assets/38c7aa3a-10ad-4f12-be8e-98bef2fec6b1)
- **HC-SR04 Support Bracket**: Located in the "Bumper" piece, it serves as support for the HC-SR04 ultrasonic sensor, allowing it to function properly.
  
![Team Violet (1)](https://github.com/user-attachments/assets/5ab16a62-822c-422b-ad45-e21efddfad0d)
- **Bumper**: Used as a extension of the Main Chassis piece, it is used to locate the HC-SR04 sensors a little further ahead so it can detect the walls more easily.
  
![Diseño sin título (2)](https://github.com/user-attachments/assets/e086b3ef-9450-4917-b05d-0d8dfc55d821)
- **Crossing System**: As it's name says, this part makes it possible to transmit the movement of the servomotor to the front wheels, thus allowing the robot to change direction.
  
![Team Violet (2)](https://github.com/user-attachments/assets/ad017619-b545-498f-b5d1-4f590f547603)

### Electronics
  -  **L298N**: Used to control the Hex Motor and the Smart Robot Servo.
> [!IMPORTANT]
> Specifications
>- Channels: 2 (supports 2 DC motors or 1 PAP motor)
>- Logic voltage: 5V.
>- Operating Voltage: 5V-35V.
>- Current consumption (Digital): 0 to 36mA.
>- Current capacity: 2A (peaks up to 3A).
>- Maximum power: 25W.
>- Weight: 30g.
   
  -   **Hex Motor**: Located in the lower module of the robot, this motor serves a rear wheel drive for the robot, providing the foward or backward motion of the robot.
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
>- At the motor - 4 counts/revolution
>- At the output - 288 counts/revolution

  -   **Smart Robot Servo**: Located alongside the Hex Motor, it gives the robot the ability to rotate the front wheels, changing the orientation of the robot, thus allowing the robot to move freely in any direction on a flat surface.
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

  -   **Arduino Mega 2560 Wifi R3**: The MEGA2560 Wifi is a variant of the Arduino programmable board* that includes an ESP8266 Wifi chip. It is used to manage the robot's mobility alongside the L298N Motor Controller, thus allowing the robot to move freely on a flat surface.
> [!IMPORTANT]
>- Microcontroller: ATmega2560
>- Input voltage: 7-12V.
>- 54 digital Input/Output pins (14 of them are PWM outputs).
>- 16 analog inputs.
>- 256k flash memory.
>- 16Mhz clock speed.

  -   **Raspberry Pi 4**: The Raspberry Pi 4 is a single-board development board used for entry-level computing. It has the purpose of managing the "Color Processing" section, thus allowing the robot to recognize colors next to them and use this information advantegiously.
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

   -   **Ultrasonic Sensor**: The robot has 3 HC-SR04 ultrasonic sensors on the left, right and front that function as a sonar. They are used to provide orientation to the robot when moving in any environment, allowing it to detect obstacles or adjacent walls.
> [!IMPORTANT]
>- Supply voltage: 5 Vcc
>- Working frequency: 40 KHz
>- Maximum range: 4.5 m
>- Minimum range: 2.0 cm
>- Minimum trigger pulse duration (TTL level): 10 μS.
>- Duration of the output echo pulse (TTL level): 100-25000 μS.
>- Minimum waiting time between one measurement and the start of another 20 mS.
  
   -   **Camera: The robot uses an 
   
   -   **3.7V 18650 Lithium Batteries**: Used to provide power to the Hex Motor and Smart Robot Servo on the lower module, this batteries have a nominal voltage of 3.7V and a maximum voltage of 4.2V and a capacity of 3500 mAh each.

   -   **ONIO 10000mAh Power Bank**: We use a ONIO 10000mAh Power Bank to supply Raspberry Pi and the Arduino Mega with energy. It has 1 USB ports, along with a Micro-USB port for charging, with an output voltage of 5V and 2.4A.


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
### Servomotor setting
The moveset of the Servomotor is define by the distance given by the ultrasonic sensors 
depending on whether the wall is close, far away or in a corner
### Lane Determination
The determination of the lane is define by the first corner, if the corner is of the rigth side it means that the direction is clockwise and 
vice versa

## Data Sending
In this case we send the information via monitor serial with the library Serial with the function ser.write

# Team History
## 2023 Season
tatatta
## Early 2024 Season
tatatata

--------------------------------------------------------------------------------------------------------------------------------------
Thank You. Team Violet - 2024.
======================================================================================================================================
