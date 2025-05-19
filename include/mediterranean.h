#ifndef MEDITERRANEAN_H
#define MEDITERRANEAN_H

#include "implant.h"

class Mediterranean : public Implant {
private:
    double temperature;
public:
    Mediterranean(const std::string &name);

    std::string activate() override;
    std::string deactivate() override;
    std::string get_all_infos() override;
};

#endif
