#ifndef DESERTIC_H
#define DESERTIC_H

#include "implant.h"

class Desertic : public Implant {
public:
    Desertic(const std::string &name);

    std::string activate() override;
    std::string deactivate() override;
    std::string get_all_infos() override;
};

#endif
