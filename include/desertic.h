#ifndef DESERTIC_H
#define DESERTIC_H

#include "implant.h"

class Desertic : public Implant {
public:
    explicit Desertic(const std::string &name);

    std::string activate(const Clock& c) override;
    std::string deactivate() override;
    std::string adaptive_behaviour(const Clock& c) override;
    std::string get_all_infos() override;
};

#endif
