#include <libsocket/libinetsocket.h>

#include "ActivateRobot.h"
#include "ReadFromSocket.h"
#include <string.h>

int ActivateRobot(int robotSocket)
{
	char activateRobotCommand[14] = "ActivateRobot ";
	int msgLength = strlen(activateRobotCommand);
	activateRobotCommand[13] = 0;
	int ret = send(robotSocket, activateRobotCommand, msgLength, 0);
	ReadFromSocket(robotSocket);
	return ret;
}
