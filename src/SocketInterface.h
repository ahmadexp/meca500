#ifndef SOCKETINTERFACE_H
#define SOCKETINTERFACE_H

#include <string>

class SocketInterface
{

public:
	virtual void send(std::string message) = 0;
};

#endif //SOCKETINTERFACE_H
