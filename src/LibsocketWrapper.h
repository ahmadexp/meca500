#ifndef LIBSOCKET_WRAPPER_H
#define LIBSOCKET_WRAPPER_H

#include <libsocket/inetclientstream.hpp>
#include <string>

#include "SocketInterface.h"

class LibsocketWrapper : public SocketInterface
{
    libsocket::inet_stream sock;
    
public:
    LibsocketWrapper(std::string host, std::string port);
    void write(std::string message);
    std::string read();
  
};
#endif //LIBSOCKET_WRAPPER_H
