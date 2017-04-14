#ifndef SENDING_H
#define SENDING_H

#include <string>

#include "SocketInterface.h"

namespace Meca500
{

class MessageSender
{
	SocketInterface *m_socket;
public:
	MessageSender(SocketInterface *socket);
	void SendMessage(std::string message);

};
}

#endif //SENDING_H
