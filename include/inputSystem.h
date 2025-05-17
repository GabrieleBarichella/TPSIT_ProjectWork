#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "clock.h"

void logMessage(const Clock &time, const std::string &message, const int &errorLevel);
std::vector<std::string> commandParser(const std::string &command);
void processCommand(const std::string &command);

#endif
