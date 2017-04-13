#include <libsocket/libinetsocket.h>

#include "DeactivateRobot.h"
#include "ReadFromSocket.h"
#include <string.h>

int DeactivateRobot(int robotSocket)
{
	char command[16] = "DeactivateRobot";
	int ret = send(robotSocket, command, 16, 0);
	ReadFromSocket(robotSocket);
	return ret;
}
