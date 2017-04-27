#include <chrono>
#include <iostream>
#include <thread>

#include "SocketWrapper.h"

SocketWrapper::SocketWrapper(std::string host, std::string port)
{
  m_host = host;
  m_port = port;
}

void SocketWrapper::write(std::string message)
{

    try
    {
	std::cout<<"Entered try block in SocketWrapper::write"<<std::endl;
	libsocket::inet_stream sock(m_host, m_port, LIBSOCKET_IPv4, 0);
	std::cout<<"Connecting to libsocket..."<<std::endl;
	sock << message;
    }
    catch(const libsocket::socket_exception& exc)
    {
	std::cout << exc.mesg;
    }	
}

std::string SocketWrapper::read()
{
    return std::string("sample string read from socket wrapper");
}

