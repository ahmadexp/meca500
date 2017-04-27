#ifndef SOCKET_WRAPPER_H
#define SOCKET_WRAPPER_H

#include <libsocket/inetclientstream.hpp>
#include <string>

#include "SocketInterface.h"

class SocketWrapper : public SocketInterface
{
    std::string m_host, m_port;
    libsocket::inet_stream sock;

public:
    SocketWrapper(std::string host, std::string port);
    void write(std::string message);
    std::string read();
  
};
#endif //SOCKET_WRAPPER_H
