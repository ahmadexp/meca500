#ifndef SOCKETINTERFACE_H
#define SOCKETINTERFACE_H

#include <string>

class SocketInterface
{

public:
	virtual void write(std::string message) = 0;
	virtual std::string read() = 0;
};

#endif //SOCKETINTERFACE_H
