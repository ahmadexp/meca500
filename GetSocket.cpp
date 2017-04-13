#include <libsocket/inetclientstream.hpp>
#include <libsocket/exception.hpp>
#include <iostream>

#include "GetSocket.h"
//#include "ReadFromSocket.h"

int GetSocket(std::string  mecaIp,std::string mecaPort)
{
	using libsocket::inet_stream;
	int ret=0;
	try{
		libsocket::inet_stream sockfd(mecaIp, mecaPort, LIBSOCKET_IPv4, 0);

		//ReadFromSocket(sockfd);
	}
	catch(const libsocket::socket_exception& exc) {
		std::cerr << exc.mesg;
	}
	return ret;	
}
