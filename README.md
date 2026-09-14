# Smart Meter Simulator

A C++ smart meter simulation project that models residential and commercial electricity meters.

The project calculates electrical power, energy consumption, estimated electricity cost, and peak power demand. It also exports all meter readings to a CSV file for further analysis.

## Features

- Residential and commercial meter types
- Power calculation
- Energy consumption calculation
- Electricity cost calculation
- Commercial service charges
- Multiple meter readings
- Total energy calculation
- Total cost calculation
- Peak power detection
- Input validation using exceptions
- CSV file export
- Object-oriented programming
- Inheritance and polymorphism
- Smart pointers using `unique_ptr`

## Engineering Calculations

Power is calculated using:

`Power = Voltage × Current`

Energy is calculated using:

`Energy (kWh) = Power (W) × Time (h) / 1000`

Residential electricity cost:

`Cost = Energy × Tariff`

Commercial electricity cost:

`Cost = Energy × Tariff + Service Charge`

## Project Structure

```text
smart-meter-simulator/
│
├── main.cpp
├── SmartMeter.h
├── SmartMeter.cpp
├── smart_meter_data.csv
└── README.md