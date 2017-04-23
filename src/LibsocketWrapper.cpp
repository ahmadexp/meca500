#include "LibsocketWrapper.h"

LibsocketWrapper::LibsocketWrapper(std::string host, std::string port)
{
    sock = libsocket::inet_stream(host, port, LIBSOCKET_IPv4);
}

void LibsocketWrapper::write(std::string message)
{
    try
    {
	sock << message;
    }
    catch(const libsocket::socket_exception& exc)
    {
	std::cerr << exc.mesg;
    }
	
}
