#ifndef CARNIVOROUS_H
#define CARNIVOROUS_H

#include "implant.h"

class Carnivorous : public Implant {
public:
    //explicit per pervenire conversioni implicite
    explicit Carnivorous(const std::string &name);

    //metodi ereditati da implant
    std::string activate(const Clock& c) override;
    std::string deactivate() override;
    std::string adaptive_behaviour(const Clock& c) override;
    std::string get_all_infos() override;
};

#endif
