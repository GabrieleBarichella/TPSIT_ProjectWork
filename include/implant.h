#ifndef IMPLANT_H
#define IMPLANT_H

#include <string>
#include "Clock.h"

class Implant {
protected:
    bool active = false;
    bool automatic = false;

    int frequency = 0;
    int duration = 0;
    Clock last_activation;

    std::string plant_name;
    int id;
    double water_usage = 0;

    Clock timer_start;
    Clock timer_stop;
    bool timer_enabled = false;

public:
    Implant(const std::string& name, int id, bool is_automatic, int freq, int dur);

    virtual ~Implant() = default;

    virtual void update(const Clock& current_time) = 0;
    virtual void turnOn(const Clock& current_time) = 0;
    virtual void turnOff(const Clock& current_time) = 0;

    virtual void printStatus() const = 0;

    void setTimer(const Clock& start, const Clock& stop);
    void removeTimer();
    bool hasTimer() const;

    std::string getPlantName() const;
    int getID() const;
    bool isActive() const;
    bool isAutomatic() const;
    double getWaterUsage() const;
};

#endif
