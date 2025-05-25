#ifndef IMPLANT_H
#define IMPLANT_H

#include <string>
#include "Clock.h"

class Implant {
protected:
    std::string plant_name;
    bool active;
    //0 = manuale, 1 = automatico, 2 = adattivo
    int implant_type;

    Clock last_activation;
    Clock timer_start;
    Clock timer_stop;

public:
    //explicit per evitare conversioni implicite
    explicit Implant(const std::string& name);

    //distruttore virtuale
    virtual ~Implant() = default;

    virtual std::string activate(const Clock& c) = 0;
    virtual std::string deactivate() = 0;
    virtual std::string adaptive_behaviour(const Clock& c) = 0;
    virtual std::string get_all_infos() = 0;

    void set_timer(const Clock& start, const Clock& stop);
    void set_timer(const Clock& start);
    void set_active(bool status);

    void remove_timers();

    //clang-tidy: nodiscard per evitare che venga ignorato ciò che viene restituito dal metodo
    [[nodiscard]] std::string get_plant_name() const;
    [[nodiscard]] bool is_active() const;
    [[nodiscard]] int get_implant_type() const;

    [[nodiscard]] Clock get_last_activation() const;
    [[nodiscard]] Clock get_timer_start() const;
    [[nodiscard]] Clock get_timer_stop() const;

};

#endif
