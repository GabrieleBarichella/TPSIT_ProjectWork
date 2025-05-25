#ifndef ALPINE_H
#define ALPINE_H

#include "implant.h"

class Alpine : public Implant {
public:
    //explicit per prevenire conversioni implicite
    explicit Alpine(const std::string& name);

    //metodi ereditati da Implant
    std::string activate(const Clock& c) override;
    std::string deactivate() override;
    std::string adaptive_behaviour(const Clock& c) override;
    std::string get_all_infos() override;
};

#endif
