#include <libsocket/libinetsocket.h>

#include "SetJoints.h"
#include "ReadFromSocket.h"
#include <string.h>

int SetJoints(int robotSocket, int j1, int j2, int j3, int j4, int j5, int j6)
{
	char command[23] = "SetJoints(1,2,3,4,5,6)";
	char temp ='3';
	sprintf(&temp,"%d",j1);
	command[10] = temp;
	sprintf(&temp,"%d",j2);
	command[12] = temp;
	sprintf(&temp,"%d",j3);
	command[14] = temp;
	sprintf(&temp,"%d",j4);
	command[16] = temp;
	sprintf(&temp,"%d",j5);
	command[18] = temp;
	sprintf(&temp,"%d",j6);
	command[20] = temp;
	int ret = send(robotSocket, command, 24, 0);
	ReadFromSocket(robotSocket);
	return ret;
}
