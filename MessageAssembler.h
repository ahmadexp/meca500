#ifndef MESSAGEASSEMBLER_H
#define MESSAGEASSEMBLER_H

#include <string>

namespace Meca500
{

bool IsKnownCommand(std::string command);
std::string AssembleMessage(std::string command);
}

#endif //MESSAGEASSEMBLER_H
