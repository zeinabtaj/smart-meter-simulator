#include "SmartMeter.h"

#include <iostream>
#include <stdexcept>

using namespace std;


// SMART METER

SmartMeter::SmartMeter(
    double v,
    double c,
    double t,
    double rate
)
{
    if (v <= 0)
    {
        throw invalid_argument(
            "Voltage must be greater than 0."
        );
    }

    if (c < 0)
    {
        throw invalid_argument(
            "Current cannot be negative."
        );
    }

    if (t <= 0)
    {
        throw invalid_argument(
            "Time must be greater than 0."
        );
    }

    if (rate < 0)
    {
        throw invalid_argument(
            "Tariff cannot be negative."
        );
    }

    voltage = v;
    current = c;
    timeHours = t;
    tariff = rate;
}


double SmartMeter::calculatePower()
{
    return voltage * current;
}


double SmartMeter::calculateEnergy()
{
    return (
        calculatePower() * timeHours
    ) / 1000.0;
}


double SmartMeter::calculateCost()
{
    return calculateEnergy() * tariff;
}


void SmartMeter::displayReading()
{
    cout << "Voltage: "
         << voltage
         << " V"
         << endl;

    cout << "Current: "
         << current
         << " A"
         << endl;

    cout << "Time: "
         << timeHours
         << " hours"
         << endl;

    cout << "Power: "
         << calculatePower()
         << " W"
         << endl;

    cout << "Energy: "
         << calculateEnergy()
         << " kWh"
         << endl;

    cout << "Cost: "
         << calculateCost()
         << endl;
}


string SmartMeter::getMeterType()
{
    return "SmartMeter";
}


double SmartMeter::getVoltage()
{
    return voltage;
}


double SmartMeter::getCurrent()
{
    return current;
}


double SmartMeter::getTimeHours()
{
    return timeHours;
}


double SmartMeter::getTariff()
{
    return tariff;
}


SmartMeter::~SmartMeter()
{
}


// RESIDENTIAL METER


ResidentialMeter::ResidentialMeter(
    double v,
    double c,
    double t,
    double rate
)
    : SmartMeter(v, c, t, rate)
{
}


double ResidentialMeter::calculateCost()
{
    return calculateEnergy() * tariff;
}


void ResidentialMeter::displayReading()
{
    cout << "\n--- Residential Meter ---"
         << endl;

    SmartMeter::displayReading();
}


string ResidentialMeter::getMeterType()
{
    return "Residential";
}


// COMMERCIAL METER

CommercialMeter::CommercialMeter(
    double v,
    double c,
    double t,
    double rate,
    double charge
)
    : SmartMeter(v, c, t, rate)
{
    serviceCharge = charge;
}


double CommercialMeter::calculateCost()
{
    return (
        calculateEnergy() * tariff
    ) + serviceCharge;
}


void CommercialMeter::displayReading()
{
    cout << "\n--- Commercial Meter ---"
         << endl;

    SmartMeter::displayReading();

    cout << "Service charge: "
         << serviceCharge
         << endl;
}


string CommercialMeter::getMeterType()
{
    return "Commercial";
}


double CommercialMeter::getServiceCharge()
{
    return serviceCharge;
}