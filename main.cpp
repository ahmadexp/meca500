#include <string>

#include "GetSocket.h"
//#include "ActivateRobot.h"
//#include "DestroySocket.h"
//#include "HomeRobot.h"
//#include "DeactivateRobot.h"
//#include "SetJoints.h"

int main()
{
	std::string MECA_IP="192.168.0.100";
	std::string MECA_PORT="10000";
	int robotSocket = GetSocket(MECA_IP, MECA_PORT);
	//ActivateRobot(robotSocket);
	//HomeRobot(robotSocket);
	//SetJoints(robotSocket,0,0,0,0,0,0);
	//DeactivateRobot(robotSocket);
	//int destroy = DestroySocket(robotSocket);
	return 0;
}
