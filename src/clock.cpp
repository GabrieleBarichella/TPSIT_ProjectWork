#include "../include/clock.h"

Clock::Clock() {
    hour = 0;
    minute = 0;
}

int Clock::get_hour() const {
    return hour;
}

int Clock::get_minute() const {
    return minute;
}

int Clock::get_total_time() const {
    return total_time;
}

void Clock::set_hour(int h) {
    hour = h;
}

void Clock::set_minute(int m) {
    minute = m;
}

std::string Clock::tostring() const {
    return std::to_string(hour) + ":" + std::to_string(minute);
}

Clock Clock::operator++(int) {
    if(minute < 59) minute++;
    else if(hour < 23) { hour++; minute = 0; }
    else { hour = 0; minute = 0; }

    total_time++;
    return *this;
}




