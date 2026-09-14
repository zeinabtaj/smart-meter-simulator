#ifndef SMARTMETER_H
#define SMARTMETER_H

#include <string>

using namespace std;


class SmartMeter
{
protected:
    double voltage;
    double current;
    double timeHours;
    double tariff;

public:
    SmartMeter(double v, double c, double t, double rate);

    double calculatePower();
    double calculateEnergy();

    virtual double calculateCost();
    virtual void displayReading();

    virtual string getMeterType();

    double getVoltage();
    double getCurrent();
    double getTimeHours();
    double getTariff();

    virtual ~SmartMeter();
};


class ResidentialMeter : public SmartMeter
{
public:
    ResidentialMeter(double v, double c, double t, double rate);

    double calculateCost() override;
    void displayReading() override;

    string getMeterType() override;
};


class CommercialMeter : public SmartMeter
{
private:
    double serviceCharge;

public:
    CommercialMeter(
        double v,
        double c,
        double t,
        double rate,
        double charge
    );

    double calculateCost() override;
    void displayReading() override;

    string getMeterType() override;

    double getServiceCharge();
};


#endif