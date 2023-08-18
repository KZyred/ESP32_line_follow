# Line Follow Robot with ESP32

This repository contains the code for a simple line-following robot using an ESP32 microcontroller. The robot utilizes 5 infrared sensors to detect and follow lines on the ground. The control algorithm is based on a Proportional-Integral-Derivative (PID) controller, allowing precise line-following behavior.

## Hardware Components

- **Microcontroller:** ESP32
- **Sensors:** 5 Infrared Sensors
- **Actuators:**
  - ZK-5AD Motor Driver
  - 2 N20 Motors

## Algorithm

The line-following algorithm is implemented using a PID controller. The PID controller adjusts the motor PWM signals based on the error calculated from the sensor readings, helping the robot stay on the desired path.

## Development Environment

The code for this project was developed using PlatformIO on Visual Studio Code.

## Project Structure

- **lib/**
  - **ESP32_Motor_Controller/**
    - `esp32_motor.h`: Defines the class for controlling motors using the ESP32's LEDC module.

  - **Line_status/**
    - `line_status.h`: Defines the class to manage infrared line sensor status.

  - **PID_controler/**
    - `PIDcontroller.h`: Defines the class for the PID controller.

- **src/**
  - `main.cpp`: The main code that initializes motors, sensors, and PID controller.

- `main.h`: Contains constants and configurations used throughout the project.

## Components and Descriptions

### ESP32_Motor_Controller (`esp32_motor.h`)

The `esp32_motor.h` file defines a class for controlling motors using the ESP32's LEDC module. It provides methods to set up motor control and to run the motors at specific PWM values or stop them.

### Line_status (`line_status.h`)

The `line_status.h` file defines a class that manages the status of the infrared line sensors. It provides methods to update sensor status and calculate the line position error based on the sensor readings.

### PID_controller (`PIDcontroller.h`)

The `PIDcontroller.h` file defines a class for the PID controller. It contains PID constants and methods to calculate the PID output.

### `main.cpp`

This main code file initializes the motors, sensors, and PID controller. It continuously reads sensor data, calculates the PID output, and controls the motors to follow the line.

### `main.h`

The `main.h` file contains constants and configurations used throughout the project, such as base PWM, PID controller constants (KP, KI, KD), and more.

## `platformio.ini`

The `platformio.ini` file specifies configuration settings for the PlatformIO environment. It defines the platform, board, framework, and upload speed for the project.

---

For more detailed information about individual components and their functions, please refer to the respective code files and comments within.
