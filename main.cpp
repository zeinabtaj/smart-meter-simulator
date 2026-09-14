#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <stdexcept>

#include "SmartMeter.h"

using namespace std;


int main()
{
    vector<unique_ptr<SmartMeter>> meters;

    int numberOfReadings;

    cout << "How many meter readings do you want to enter? ";
    cin >> numberOfReadings;


    for (int i = 0; i < numberOfReadings; i++)
    {
        int meterType;

        cout << "\nReading "
             << i + 1
             << endl;

        cout << "Choose meter type:"
             << endl;

        cout << "1. Residential"
             << endl;

        cout << "2. Commercial"
             << endl;

        cout << "Choice: ";
        cin >> meterType;


        double voltage;
        double current;
        double timeHours;
        double tariff;


        cout << "Enter voltage (V): ";
        cin >> voltage;

        cout << "Enter current (A): ";
        cin >> current;

        cout << "Enter time (hours): ";
        cin >> timeHours;

        cout << "Enter tariff per kWh: ";
        cin >> tariff;


        try
        {
            if (meterType == 1)
            {
                meters.push_back(
                    make_unique<ResidentialMeter>(
                        voltage,
                        current,
                        timeHours,
                        tariff
                    )
                );
            }

            else if (meterType == 2)
            {
                double serviceCharge;

                cout << "Enter commercial service charge: ";
                cin >> serviceCharge;

                meters.push_back(
                    make_unique<CommercialMeter>(
                        voltage,
                        current,
                        timeHours,
                        tariff,
                        serviceCharge
                    )
                );
            }

            else
            {
                cout << "Invalid meter type."
                     << endl;

                i--;

                continue;
            }
        }

        catch (const invalid_argument& error)
        {
            cout << "\nInvalid input: "
                 << error.what()
                 << endl;

            i--;
        }
    }


    double totalEnergy = 0;
    double totalCost = 0;
    double peakPower = 0;


    cout << "\n=========================="
         << endl;

    cout << "ALL METER READINGS"
         << endl;

    cout << "=========================="
         << endl;


    for (int i = 0; i < meters.size(); i++)
    {
        meters[i]->displayReading();

        totalEnergy +=
            meters[i]->calculateEnergy();

        totalCost +=
            meters[i]->calculateCost();

        double currentPower =
            meters[i]->calculatePower();

        if (currentPower > peakPower)
        {
            peakPower = currentPower;
        }
    }


    cout << "\n=========================="
         << endl;

    cout << "SUMMARY"
         << endl;

    cout << "=========================="
         << endl;

    cout << "Total energy: "
         << totalEnergy
         << " kWh"
         << endl;

    cout << "Total cost: "
         << totalCost
         << endl;

    cout << "Peak power: "
         << peakPower
         << " W"
         << endl;


    // ==========================
    // SAVE TO CSV
    // ==========================

    ofstream outputFile(
        "smart_meter_data.csv"
    );


    if (!outputFile)
    {
        cout << "\nError creating CSV file."
             << endl;

        return 1;
    }


    outputFile
        << "Reading,"
        << "MeterType,"
        << "Voltage,"
        << "Current,"
        << "TimeHours,"
        << "Power_W,"
        << "Energy_kWh,"
        << "Tariff,"
        << "Cost"
        << "\n";


    for (int i = 0; i < meters.size(); i++)
    {
        outputFile
            << i + 1 << ","
            << meters[i]->getMeterType() << ","
            << meters[i]->getVoltage() << ","
            << meters[i]->getCurrent() << ","
            << meters[i]->getTimeHours() << ","
            << meters[i]->calculatePower() << ","
            << meters[i]->calculateEnergy() << ","
            << meters[i]->getTariff() << ","
            << meters[i]->calculateCost()
            << "\n";
    }


    outputFile.close();


    cout << "\nData saved to smart_meter_data.csv"
         << endl;


    return 0;
}