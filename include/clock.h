#ifndef CLOCK_H
#define CLOCK_H
#include <string>

class Clock {
private:
    int hour;
    int minute;
public:
    [[nodiscard]] int get_hour() const;
    [[nodiscard]] int get_minute() const;
    [[nodiscard]] int get_total_time() const;
    void set_hour(int h);
    void set_minute(int m);
    void set_total_time(int t);
    [[nodiscard]] std::string tostring() const;
    Clock operator++(int);

    Clock();
    explicit Clock(const std::string &time);
};

#endif