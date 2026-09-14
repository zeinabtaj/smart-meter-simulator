# Smart Meter Simulator

A C++ smart meter simulation project designed to model residential and commercial electricity usage.

The program calculates electrical power, energy consumption, estimated electricity cost, and peak power demand. It also exports meter readings to a CSV file for further analysis.

The project was developed to practise applying object-oriented C++ programming to an electrical engineering application.

---

## Features

- Residential and commercial smart meter types
- Multiple meter readings
- Electrical power calculation
- Energy consumption calculation
- Electricity cost estimation
- Commercial service charges
- Total energy consumption calculation
- Total electricity cost calculation
- Peak power detection
- Input validation using exception handling
- CSV data export
- Object-oriented program structure
- Automatic memory management using smart pointers

---

## Engineering Calculations

The simulator uses basic electrical power and energy relationships.

### Power

Electrical power is calculated using:

`Power (W) = Voltage (V) × Current (A)`

For example, for a 230 V supply drawing 4 A:

`Power = 230 × 4 = 920 W`

### Energy Consumption

Energy consumption is calculated from power and operating time:

`Energy (kWh) = Power (W) × Time (hours) / 1000`

For a 920 W load operating for 2 hours:

`Energy = 920 × 2 / 1000 = 1.84 kWh`

### Residential Electricity Cost

For residential meters:

`Cost = Energy × Tariff`

### Commercial Electricity Cost

Commercial meters include an additional service charge:

`Cost = (Energy × Tariff) + Service Charge`

---

## Example

Example commercial meter input:

```text
Meter type: Commercial
Voltage: 230 V
Current: 4 A
Time: 2 hours
Tariff: 0.25 per kWh
Service charge: 1.50
```

The simulator calculates:

```text
Power: 920 W
Energy: 1.84 kWh
Cost: 1.96
```

---

## Multiple Meter Readings

The program can process multiple meter readings during a single run.

Each reading is stored in a vector and can represent either a residential or commercial meter.

After all readings have been entered, the program calculates:

- Total energy consumption
- Total estimated electricity cost
- Peak power demand

This allows the simulator to provide both individual meter information and an overall consumption summary.

---

## Residential and Commercial Meters

The project uses inheritance to represent different types of electricity meters.

`SmartMeter` acts as the base class and contains the common properties and calculations required by all meters.

Two derived classes are implemented:

```text
SmartMeter
   |
   |-- ResidentialMeter
   |
   |-- CommercialMeter
```

`ResidentialMeter` uses the standard energy tariff calculation.

`CommercialMeter` extends the calculation by including an additional service charge.

Virtual functions allow the correct cost calculation and display behaviour to be selected depending on the type of meter being processed.

---

## CSV Data Export

After processing the readings, the program exports the results to:

`smart_meter_data.csv`

The CSV file contains:

- Reading number
- Meter type
- Voltage
- Current
- Operating time
- Power
- Energy consumption
- Tariff
- Calculated cost

Example:

```csv
Reading,MeterType,Voltage,Current,TimeHours,Power_W,Energy_kWh,Tariff,Cost
1,Commercial,230,4,2,920,1.84,0.25,1.96
```

The exported data can be opened in spreadsheet software or used for further analysis in tools such as Python.

---

## C++ Concepts Used

This project demonstrates several core C++ programming concepts.

### Object-Oriented Programming

Classes are used to represent different types of smart meters and keep related data and behaviour together.

### Encapsulation

Meter properties such as voltage, current, operating time, and tariff are stored inside the meter classes rather than being managed directly by the main program.

### Constructors

Constructors initialise meter objects and validate the supplied electrical data.

### Inheritance

`ResidentialMeter` and `CommercialMeter` inherit common functionality from the `SmartMeter` base class.

### Polymorphism

Virtual functions allow residential and commercial meter objects to provide different behaviour while being accessed through the same `SmartMeter` interface.

### Method Overriding

Derived meter classes override functions such as cost calculation and meter type identification.

### Smart Pointers

`unique_ptr` and `make_unique` are used to manage dynamically created meter objects without requiring manual memory deletion.

### Vectors

A `vector` stores multiple smart meter objects so that any number of readings can be processed.

### Exception Handling

Invalid electrical values are handled using `throw`, `try`, and `catch`.

### File Handling

The `<fstream>` library is used to create and write the CSV output file.

### Multi-File Program Structure

The project separates class declarations, class implementations, and the main program into different files.

---

## Project Structure

```text
smart-meter-simulator/
|
|-- main.cpp
|-- SmartMeter.h
|-- SmartMeter.cpp
|-- smart_meter_data.csv
|-- README.md
|-- .gitignore
```

### `main.cpp`

Controls the main program flow, including:

- User input
- Creating meter objects
- Storing readings
- Calculating totals
- Finding peak power
- Exporting results to CSV

### `SmartMeter.h`

Contains the declarations for:

- `SmartMeter`
- `ResidentialMeter`
- `CommercialMeter`

### `SmartMeter.cpp`

Contains the implementations of the meter constructors, calculations, display functions, and other class methods.

### `smart_meter_data.csv`

Contains example output generated by the simulator.

---

## Compilation

The project uses C++17.

Compile the program using:

```bash
g++ -std=c++17 main.cpp SmartMeter.cpp -o main
```

Then run it using:

```bash
./main
```

---

## Input Validation

The simulator checks that electrical inputs are within valid ranges.

For example:

- Voltage must be greater than zero
- Current cannot be negative
- Operating time must be greater than zero
- Tariff cannot be negative

Invalid values generate an exception rather than creating an invalid meter object.

---

## What I Learned

This project helped me practise applying C++ to an electrical engineering problem rather than using the language only for isolated programming exercises.

Key areas developed during the project include:

- Designing classes around engineering concepts
- Structuring a C++ project across header and source files
- Using inheritance to represent related meter types
- Applying runtime polymorphism with virtual functions
- Using smart pointers for safer memory management
- Storing multiple objects using vectors
- Handling invalid data using exceptions
- Writing program output to CSV files
- Applying electrical power and energy equations in software
- Combining programming concepts into a complete engineering application

---

## Future Improvements

The simulator could be extended with more realistic smart-grid and energy-management features, including:

- Time-of-use electricity tariffs
- Different peak and off-peak electricity prices
- Daily and monthly energy reports
- Importing meter readings from CSV files
- Energy consumption alerts
- Demand profiling
- Solar PV generation
- Grid import and export calculations
- Net household energy consumption
- Battery energy storage modelling
- Python-based analysis and visualisation of exported meter data

A future extension could combine the simulator with renewable generation data to investigate how solar PV affects household grid consumption and electricity costs.

---

## Purpose

This project was created as a practical C++ learning project alongside my Electrical and Electronic Engineering studies.

The aim was to strengthen my understanding of object-oriented programming while applying the concepts to electrical power and energy measurement.