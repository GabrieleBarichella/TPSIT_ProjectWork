#ifndef TROPICAL_H
#define TROPICAL_H

#include "implant.h"

class Tropical : public Implant {
public:
    Tropical(const std::string &name);

    std::string activate() override;
    std::string deactivate() override;
    std::string get_all_infos() override;
};

#endif
