# Engineering Documentation - Team Violet 
![Team Violet](https://github.com/user-attachments/assets/9c2fd371-100e-4b94-a8dc-27d999703344)
## Introduction
In this repository you will find all the information related to the construction and assembly of the autonomous robot built by _Team Violet_ for the Future Engineers category in the 2025 Season.
This has been an incredible journey with a lot of obstacles, and we have done our best to come up with a design that we were not only satisfied with, but one that could properly acomplish all of the objectives present in this edition of the "Future Engineers" category.

## Contents
- [Team Violet's Members](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#team-violets-members)
- [Hardware Design](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#hardware-design)
   - [Design Process](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#design-process)
   - [Assembly Process](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#assembly-process)
   - [Elements](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#elements)
     - [3D Printed](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#3d-printed)
     - [Electronics](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#electronics)
- [Software Design](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#software-design)
   - [Image and Color Processing](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#image-and-color-processing)
     - [Image Capturing](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#image-capturing)
     - [Creating Red and Green masks](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#creating-red-and-green-masks)
     - [Final Image](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#final-image)
     - [Distance from the cones](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#location-from-the-cones)
   - [Robot Movement](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#robot-movement)
     - [Smart Robot Servo configuration](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#smart-robot-servo-configuration)
     - [Robot Orientation](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#robot-orientation)
     - [Route Determination](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#route-determination)
   - [Data Sending](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#data-sending)
 - [Impact](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/blob/main/README.md#impact)

# Team Violet's Members
 - Adrian Alvarez:

![image](https://github.com/user-attachments/assets/01bdc9a7-1ad9-40bc-ae4c-89c82bd9f1e7)

>Hi, my name is Adrian Alvarez, I'm part of Team Violet and I'm responsible for the 3D designs used in the robot. My expectations of this competition are to learn and to test my skills in robotics.
 - Reinaldo Belmonte:

![image](https://github.com/user-attachments/assets/181e0041-2fbb-4ff6-b8b1-abc1b730d39e)

   
>My name is Reinaldo Belmonte. I am the team's programmer and I'm responsible for developing most (if not all) of the robot's moveset. My expectations for this season is to do my best with this project and, hopefully, end up in the first places.
 - Jose Zambrano:

![image](https://github.com/user-attachments/assets/f6a6fa98-6a3a-4fed-b37b-d4e880ce9ac3)
   
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

![image](https://github.com/user-attachments/assets/3b8a519e-7d4c-4e87-a9cf-134a496dc6d5)

The final design of the robot is intended as a modular design, consisting of 3 modules: lower «traction» module, middle «sensor processing» module, and upper «power supply and color processing» module. This makes it easier to make repairs on any of the modules or to replace or rearrange parts.

![image](https://github.com/user-attachments/assets/d1e977a4-3c6f-47d1-8bdc-23a5092dba35)

With all these changes made, a [3D design](https://github.com/reiruso07/WRO2024_Future_Engineers-Team-Violet/tree/main/other/model_structure) for the entire structure of the robot was made, thus facilitating its visualization and analysis.


## Assembly Process
The assembly process of the robot was divided into each module separately to later unify all the modules into a single robot. The assembly of the lower module started looking for different references on the internet to find an ideal location to place all the corresponding motors. After finding the ideal locations for each motor, the parts of the main chassis and the turning system were designed and 3D printed, tailored to each element to optimize the performance of the robot. 

Following this, we started the assembly of the second module, being much easier to carry out, since instead of using a 3d printed piece, we used a piece of compressed cardboard as a base to place all the elements of the second module. When performing this part of the assembly, we performed some functional tests to ensure that everything worked properly; there we realized that the HC-SR04 sensors suffered from detection failures due to how they were placed in the robot, so we designed an extension of the base to place them there, thus solving the problem.

Finally, we started the assembly of the 3rd and last module, following a sequence very similar to the previous one: We use a piece of compressed cardboard as the base of the 3rd module and place the corresponding elements.

And to unify the design, we drilled holes in the 3 bases of each module (except the main chassis which was already designed with these holes in mind) and joined them with multiple “pillar shafts” in a tower shape.

You can see the respective connections in the diagram below:

![Team Violet (7)](https://github.com/user-attachments/assets/bff7452e-ade1-47f9-b08e-2854ddbcf0d5)

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

- **Crossing System Support Piece**: The function of this piece is to join or support the two wheels, in other words, it is the one that produces a support point for them, which allows them to rotate on a fixed axle.

![image](https://github.com/user-attachments/assets/1736892f-6d28-42b9-a003-4cf2a5510d00)

### Electronics
  -  **L298N Motor Driver**: Located in the middle module, it is used to manage the Hex Motor and provide both the Hex Motor and the Smart Robot Servo with energy.

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

![image](https://github.com/user-attachments/assets/16d9b2bd-6199-470e-949e-5504afcfad55)

> [!IMPORTANT]
>Specifications
>- Output Shaft: 5mm Female Hex
>- Weight: 199g.
>- Voltage: 12V DC
>- Free Speed: 125 RPM
>- Stall Torque: 3.2 N-m
>- Stall Current: 4.4 A
>- Gear Ratio: 72:1
>- Encoder Counts per Revolution
>- At the motor: 4 counts/revolution
>- At the output: 288 counts/revolution

  -   **Smart Robot Servo**: Located alongside the Hex Motor, it gives the robot the ability to rotate the front wheels, changing the orientation of the robot, thus allowing the robot to move freely in any direction on a flat surface.

![image](https://github.com/user-attachments/assets/87edde50-d0a1-4d55-b4a1-42cf02521a0a)

> [!IMPORTANT]
>- Specifications
>- Weight: 58g.
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

  -   **Arduino Mega 2560 R3**: Located in the middle module, it is used to manage the robot's mobility alongside the L298N Motor Driver, thus allowing the robot to move freely on a flat surface.

![10](https://github.com/user-attachments/assets/c5fc0711-7ad3-4b76-a04e-9142b096499a)

> [!IMPORTANT]
>- Microcontroller: ATmega2560
>- Input voltage: 7-12V.
>- 54 digital Input/Output pins (14 of them are PWM outputs).
>- 16 analog inputs.
>- 256k flash memory.
>- 16Mhz clock speed.

  -   **Raspberry Pi 4**: The Raspberry Pi 4 is a single-board development board used for entry-level computing. It is located in the upper module and it has the purpose of managing the "Color Processing" section, thus allowing the robot to recognize adjacent colors and use this information advantegiously.

![image](https://github.com/user-attachments/assets/954561bf-8419-4184-868b-522318e37c8a)

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

![image](https://github.com/user-attachments/assets/5ba9f7f5-cc90-410c-a1e0-8072fd2e3875)

> [!IMPORTANT]
>- Supply voltage: 5 Vcc
>- Working frequency: 40 KHz
>- Maximum range: 4.5 m
>- Minimum range: 2.0 cm
>- Minimum trigger pulse duration (TTL level): 10 μS.
>- Duration of the output echo pulse (TTL level): 100-25000 μS.
>- Minimum waiting time between one measurement and the start of another: 20 mS.
  
   -   **Camera**: The robot uses an Spedal MF920P Webcam to recognize the colors in the environment. It has a Full HD 1080p resolution at 30 fps, with a H.264 Video Compression and a microphone incorporated.

![image](https://github.com/user-attachments/assets/31cf36f8-b7f6-46da-850e-50dbe45a40a3)
   
   -   **3.7V 18650 Lithium Batteries**: Used to provide power to the Hex Motor and Smart Robot Servo on the lower module, this batteries have a nominal voltage of 3.7V and a maximum voltage of 4.2V and a capacity of 3500 mAh each.

![14](https://github.com/user-attachments/assets/79db2eeb-5267-411f-9fe3-d607a09bea8a)

   -   **LDNIO 10000mAh Power Bank**: We use a LDNIO 10000mAh Power Bank to supply Raspberry Pi and the Arduino Mega with energy. It has 1 USB ports, along with a Micro-USB port for charging, with an output voltage of 5V and 2.4A.

![image](https://github.com/user-attachments/assets/9f1f7ef6-66c7-4fef-86e4-b7abd323efb0)


# Software Design
## Image and Color Processing
### Image Capturing
For color detection, the Spedal MF920P camera is used to capture a frame which is processed with Python thanks to the OpenCV image manipulation library.
### Creating Red and Green masks
OpenCV reads the images or frames in BGR, therefore it is necessary to transform them to the HSV color space. This is because the parameters that we are going to give to identify the colors work in the HSV model (Hue, Saturation, Value). To do this we will use the function `cv2.cvtColor`, as first argument we will give the image to transform, and then `cv2.COLOR_BGR2HSV`, to indicate that we will transform from BGR to HSV.
The parameters used to identify red were: 

    rojobajo1=np.array([0,150,20],np.uint8)


    rojoalto1=np.array([3,255,255],np.uint8)


    rojobajo2=np.array([175,100,20],np.uint8)


    rojoalto2=np.array([179,255,255],np.uint8)

and the parameters used for green were:
  
    verdebajo=np.array([35,100,20],np.uint8)


    verdealto=np.array([80,255,255],np.uint8)

The result of these procedures is a binary image in which the whites are the colors detected with the parameters given above. This image will be used later to obtain the final image.

![Team Violet (1)](https://github.com/user-attachments/assets/81629bd2-870a-4ea8-9536-24d4c8017279)

### Final Image
To obtain the final image we will use the functions `cv2.findContours` and `cv2.drawContours` from the OpenCV library. The function `cv2.findContours` is used to identify the colors detected in the binary image that together with the function `cv2.drawContours` is used to mark the obstacles in the final image.
### Location from the cones
To identify how far the cones are from the robot, the image is divided into four positions:

![Team Violet (3)](https://github.com/user-attachments/assets/1cff6c07-f8c3-4df2-9cc2-2b0ea111c603)
1, 2, 3, and 4

The higher the position means that the obstacle is farther away from the robot, and with this information be able to calculate how much the robot has to move to avoid the cones more effectively.

## Robot Movement
### Smart Robot Servo configuration
The Smart Robot Servo is set on Pin 7 of the Arduino Mega and is configured with `Servo.write` function. The moveset of the Smart Robot Servo is defined by the distance given by the HC-SR04 sensors depending on whether the walls are near, far away or in a corner.
### Robot Orientation
The orientation of the robot is defined by the first corner, if the corner is of the rigth side it means that the direction is clockwise and 
vice versa.
### Route Determination
The determination of the routes is based on the color of the cone next to the robot. If the Python code detects a color this information will be sent to the arduino and transformed into a left or right turn depending on the detected color.

## Data Sending
First of all, we import the `smbus` library and then declare the `i2c identifier` that the Raspberry Pi 5 will have, additionally, the `i2c address` that the Raspberry Pi 5 has is placed, which is obtained thanks to a command executed in the terminal; then we create a function in charge of sending the information to the Arduino Mega 2560 R3 through an i2c connection that consist in three wires SDA (Serial Data Line), SCL (Serial Clock Line), and GND.

# Impact
The goal of this project is to evaluate the capabilities of the autonomous robot in fulfilling the various tasks that the competition demands. In the course of achieving these objectives, we had to develop a variety of skills to be able to meet all the objectives successfully, some of these skills being: the ability to analyze and correct errors in the programming of the project (both in the mobility section and in the color processing section), having to detect and correct these errors quickly in order to make progress in the expected completion times. Another of these skills was 3D design, which we used frequently to create different parts that were necessary to allow or facilitate the proper functioning of all components present in the robot.

The development of this project for the Future Engineers category was quite a journey to come up with a design that could stand up to the challenges we faced, and regardless of the outcome, it will be worth all the effort we made, since in the end, it made us grow.

--------------------------------------------------------------------------------------------------------------------------------------
Thank You. Team Violet - 2024.
======================================================================================================================================
