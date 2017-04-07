#include <libsocket/libinetsocket.h>
#include <sys/fcntl.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GetSocket.h"
#include "ReadFromSocket.h"

int GetSocket(const char * mecaIp, const char *mecaPort)
{
	static const char BUFFER_SIZE=50;//size of response from meca500 is 46
	int sockfd, bytes, ret;
	char buf[BUFFER_SIZE];

	memset(&buf, 0, sizeof buf);

	sockfd = create_inet_stream_socket(mecaIp, mecaPort, LIBSOCKET_IPv4, 0);

	if(sockfd < 0) {
		perror(0);
		exit(1);
	}
	ReadFromSocket(sockfd, buf, sizeof buf);

	return sockfd;	
}
