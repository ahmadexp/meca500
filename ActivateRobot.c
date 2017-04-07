#include <libsocket/libinetsocket.h>

#include "ActivateRobot.h"
#include "ReadFromSocket.h"

int ActivateRobot(int robotSocket)
{
	char activateRobotCommand[14] = "ActivateRobot ";
	int msgLength = strlen(activateRobotCommand);
	activateRobotCommand[13] = '\0';
	int ret = send(robotSocket, activateRobotCommand, msgLength, 0);
	
	struct timeval tv;
	fd_set readfds;
	char buf[100];	
	memset(buf,0,sizeof buf);

	ReadFromSocket(robotSocket, buf, sizeof buf);
	return ret;
}
