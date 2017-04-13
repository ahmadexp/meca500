#include <libsocket/libinetsocket.h>

#include "ActivateRobot.h"
#include "ReadFromSocket.h"
#include <string.h>

int ActivateRobot(int robotSocket)
{
	char activateRobotCommand[14] = "ActivateRobot";
	int ret = send(robotSocket, activateRobotCommand, 14, 0);
	ReadFromSocket(robotSocket);
	return ret;
}
