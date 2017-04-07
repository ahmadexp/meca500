#include <libsocket/libinetsocket.h>
#include <string.h>

#include "ReadFromSocket.h"

int ReadFromSocket(int sockfd, char *buf, int msgLength)
{
	struct timeval tv;
	fd_set readfds;
	
	tv.tv_sec=2;
	tv.tv_usec=0;

	FD_ZERO(&readfds);
	FD_SET(sockfd, &readfds);

	select(sockfd + 1, &readfds, NULL, NULL, &tv);
	
	if(FD_ISSET(sockfd, &readfds)) {
		read(sockfd, buf, msgLength-1);
		printf("%s\n",buf);
	}
	else {
		printf("Timed out");
	}

	return 0;
}
