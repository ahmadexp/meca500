#include "SocketInterface.h"
#include "Socket_Fake.h"
#include "Exception.h"

Socket_Fake::Socket_Fake()
{
}

void Socket_Fake::send(std::string message)
{
	throw(Meca500::Exception("ERROR: Sending message timed out."));
}

