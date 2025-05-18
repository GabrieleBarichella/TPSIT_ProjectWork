#ifndef CARNIVOROUS_H
#define CARNIVOROUS_H

#include "implant.h"

class Carnivorous : public Implant {
public:
    Carnivorous(const std::string &name);

    void activate() override;
    void deactivate() override;
    std::string get_all_infos() override;
};

#endif
