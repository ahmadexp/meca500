#ifndef SOCKET_FAKE_H
#define SOCKET_FAKE_H

#include <string>

#include "SocketInterface.h"

class Socket_Fake : public SocketInterface
{


public:
	Socket_Fake();

	void write(std::string message);
	std::string read();
};

#endif //SOCKET_FAKE_H
