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

void Clock::set_hour(int h) {
    hour = h;
}

void Clock::set_minute(int m) {
    minute = m;
}

void Clock::operator++() {
    if(minute < 59) minute++;
    else if(hour < 23) { hour++; minute = 0; }
    else { hour = 0; minute = 0; }
}




