#include "GetSocket.h"
#include "ActivateRobot.h"
#include "DestroySocket.h"


int main()
{
	static const char *MECA_IP="192.168.0.100";
	static const char *MECA_PORT="10000";
	int robotSocket = GetSocket(MECA_IP, MECA_PORT);
	ActivateRobot(robotSocket);
//	int destroy = DestroySocket(robotSocket);
	return 0;
}
