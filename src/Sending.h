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
    void SendMessageWithTimeout(std::string message, int secondsToWait);

};
}

#endif //SENDING_H
