#ifndef ALPINE_H
#define ALPINE_H

#include "implant.h"

class Alpine : public Implant {
public:
    Alpine(const std::string& name);

    std::string activate() override;
    std::string deactivate() override;
    std::string get_all_infos() override;
};

#endif
