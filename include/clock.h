#ifndef CLOCK_H
#define CLOCK_H

class Clock {
private:
    int hour;
    int minute;
public:
    int get_hour() const;
    int get_minute() const;
    void set_hour(int h);
    void set_minute(int m);
    void operator++();

    Clock();
};

#endif