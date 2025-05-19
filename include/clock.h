#ifndef CLOCK_H
#define CLOCK_H
#include <string>

class Clock {
private:
    int hour;
    int minute;
    int total_time;
public:
    int get_hour() const;
    int get_minute() const;
    int get_total_time() const;
    void set_hour(int h);
    void set_minute(int m);
    void set_total_time(int t);
    std::string tostring() const;
    Clock operator++(int);

    Clock();
    Clock(std::string time);
};

#endif