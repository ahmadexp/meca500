#ifndef SOCKET_FAKE_H
#define SOCKET_FAKE_H

#include <string>

#include "SocketInterface.h"

class Socket_Fake : public SocketInterface
{


public:
	Socket_Fake();

	void send(std::string message);

};

#endif //SOCKET_FAKE_H
