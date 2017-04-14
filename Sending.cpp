#include "Sending.h"
#include "Exception.h"
namespace Meca500
{

MessageSender::MessageSender(SocketInterface *socket)
{
	m_socket = socket;
}

void MessageSender::SendMessage(std::string message)
{
	try
	{
		m_socket->send(message);
	}
	catch(Meca500::Exception e)
	{
		throw e;
	}
}

}

