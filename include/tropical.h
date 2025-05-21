#ifndef TROPICAL_H
#define TROPICAL_H

#include "implant.h"

class Tropical : public Implant {
public:
    explicit Tropical(const std::string &name);

    std::string activate(const Clock& c) override;
    std::string deactivate() override;
    std::string adaptive_behaviour(const Clock& c) override;
    std::string get_all_infos() override;
};

#endif
