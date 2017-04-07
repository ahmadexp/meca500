#include <libsocket/libinetsocket.h>
#include <string.h>
#include <stdio.h>
#include "ReadFromSocket.h"

int ReadFromSocket(int sockfd)
{
	static const int MSG_LENGTH = 100;
	char buf[MSG_LENGTH];
	struct timeval tv;
	fd_set readfds;
	
	memset(buf, 0, MSG_LENGTH);

	tv.tv_sec=2;
	tv.tv_usec=0;

	FD_ZERO(&readfds);
	FD_SET(sockfd, &readfds);

	select(sockfd + 1, &readfds, NULL, NULL, &tv);
	
	if(FD_ISSET(sockfd, &readfds)) {
		read(sockfd, buf, MSG_LENGTH-1);
		printf("%s\n",buf);
	}
	else {
		printf("Timed out");
	}

	return 0;
}
