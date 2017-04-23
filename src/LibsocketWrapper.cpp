#include <iostream>

#include "LibsocketWrapper.h"

LibsocketWrapper::LibsocketWrapper(std::string host, std::string port)
{
    m_host = host;
    m_port = port;
}

void LibsocketWrapper::write(std::string message)
{
    libsocket::inet_stream sock(m_host, m_port, LIBSOCKET_IPv4);
    try
    {
	sock << message;
    }
    catch(const libsocket::socket_exception& exc)
    {
	std::cerr << exc.mesg;
    }	
}

std::string LibsocketWrapper::read()
{
    return std::string("sample string read from libsocket wrapper");
}
