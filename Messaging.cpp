#include <algorithm>
#include <vector>

#include "Messaging.h"


namespace Meca500
{

static const std::vector<std::string> knownCommands = {
"ActivateRobot"};

bool IsKnownCommand(std::string command)
{
	auto it = std::find(knownCommands.begin(), knownCommands.end(), command);
	return(it != knownCommands.end());
}

}
