#ifndef MEDITERRANEAN_H
#define MEDITERRANEAN_H

#include "implant.h"

class Mediterranean : public Implant {
private:
    double temperature;
public:
    //explicit per prevenire conversioni implicite
    explicit Mediterranean(const std::string &name);

    //metodi ereditati da implant
    std::string activate(const Clock& c) override;
    std::string deactivate() override;
    std::string adaptive_behaviour(const Clock& c) override;
    std::string get_all_infos() override;
};

#endif
