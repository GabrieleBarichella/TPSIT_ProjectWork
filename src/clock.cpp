#include "../include/clock.h"
#include <stdexcept>

Clock::Clock() : hour{0}, minute{0} {}

Clock::Clock(const std::string &time) {
    if (time.length() != 5 || time[2] != ':') {
        throw std::invalid_argument("Formato orario non valido. Deve essere HH:MM");
    }

    int h = (time[0] - '0') * 10 + (time[1] - '0');
    int m = (time[3] - '0') * 10 + (time[4] - '0');

    if (h < 0 || h > 23 || m < 0 || m > 59) {
        throw std::invalid_argument("Valori ora o minuti non validi.");
    }

    hour = h;
    minute = m;
}

int Clock::get_hour() const {
    return hour;
}

int Clock::get_minute() const {
    return minute;
}

int Clock::get_total_time() const {
    return hour * 60 + minute;
}

void Clock::set_hour(int h) {
    hour = h;
}

void Clock::set_minute(int m) {
    minute = m;
}

void Clock::set_total_time(int t) {
    hour = t / 60;
    minute = t % 60;
}

std::string Clock::tostring() const {
    std::string hour_string = (hour < 10 ? "0" : "") + std::to_string(hour);
    std::string minute_string = (minute < 10 ? "0" : "") + std::to_string(minute);
    return hour_string + ":" + minute_string;
}

Clock Clock::operator++(int) {
    if(minute < 59) minute++;
    else if(hour < 23) { hour++; minute = 0; }
    else { hour = 0; minute = 0; }

    return *this;
}




