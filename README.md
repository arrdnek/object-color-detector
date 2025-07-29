# Color Sorting Robot Simulation using Arduino Uno and TCS34725

This project simulates an automated color sorting system using Arduino Uno, the TCS34725 color sensor, and a servo motor. It is designed to detect the color of objects (red, green, or blue) and sort them accordingly by rotating the servo to a predefined position.

## Project Purpose

This project simulates an automated color sorting system inspired by real-world industrial applications, particularly in fruit packaging factories. For example, in apple processing plants, color is often used as a key indicator of ripeness and quality. Automated systems detect the surface color of apples and sort them accordingly—red apples may indicate ripeness, green for different varieties or unripe fruit, and so on.

The goal of this simulation is to mimic that industrial color sorting process on a small scale using an Arduino Uno, TCS34725 color sensor, and servo motor. The system classifies objects by color and physically separates them, demonstrating how embedded systems can be used in agricultural automation.

## System Overview

- **TCS34725 Color Sensor** reads the RGB values of an object.
- **Arduino Uno** processes the color data and makes decisions.
- **Servo Motor** rotates to a specific angle based on the dominant color detected.
- The servo resets to 0° after every detection cycle.

## Features

- Real-time color classification using RGB thresholds
- Servo motor acts as a physical sorting actuator
- Functional color logic implementation in Arduino C++
- Practical demonstration of embedded system control logic

## Components

- 1x Arduino Uno
- 1x TCS34725 Color Sensor
- 1x Servo Motor (connected to pin 9)
- Jumper wires
- Colored objects (red, green, blue)
- Optional: physical sorting frame made from popsicle sticks or cardboard

## Functional Logic

```cpp
- Read RGB values from the TCS34725 sensor.
- If all values are below 130, do nothing (too dark or no object).
- If red is dominant → rotate servo to 60°
- Else if green is dominant → rotate servo to 120°
- Else if blue is dominant → rotate servo to 180°
- Wait for 5 seconds.
- Reset servo to 0°.
- Wait for 5 seconds before next reading.
