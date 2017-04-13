#include <libsocket/libinetsocket.h>

#include "HomeRobot.h"
#include "ReadFromSocket.h"
#include <string.h>

int HomeRobot(int robotSocket)
{
	char command[14] = "Home";
	int ret = send(robotSocket, command, 5, 0);
	ReadFromSocket(robotSocket);
	return ret;
}
