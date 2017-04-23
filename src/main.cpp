#include "Exception.h"
#include "MessageAssembler.h"
#include "Sending.h"
#include "LibsocketWrapper.h"


int main()
{
  //Meca500 meca();
    LibsocketWrapper mecaSocket("192.168.0.100", "10000");
  Meca500::MessageSender sender(dynamic_cast<SocketInterface *>(&mecaSocket));
  try
    {
	sender.SendMessageWithTimeout(Meca500::AssembleMessage("ActivateRobot"),2);
    }
  catch(Meca500::Exception e){
      std::cout << e.what();
  }
  	//int robotSocket = GetSocket(MECA_IP, MECA_PORT);
	//ActivateRobot(robotSocket);
	//HomeRobot(robotSocket);
	//SetJoints(robotSocket,0,0,0,0,0,0);
	//DeactivateRobot(robotSocket);
	//int destroy = DestroySocket(robotSocket);
	return 0;
}
