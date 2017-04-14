#include <algorithm>
#include <vector>

#include "Exception.h"
#include "MessageAssembler.h"


namespace Meca500
{

static const std::vector<std::string> knownCommands = {
"ActivateRobot"};

bool IsKnownCommand(std::string command)
{
	auto it = std::find(knownCommands.begin(), knownCommands.end(), command);
	return(it != knownCommands.end());
}

std::string AssembleMessage(std::string command)
{
	if(IsKnownCommand(command) == false) {
		throw(Exception("ERROR: Command not known."));
	}
	return command;
}
}
