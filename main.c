#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>

#include <arpa/inet.h>

static const int MAX_DATA_SIZE = 1024;

int main(int argc, char *argv[])
{	
	int sockfd, numbytes;
	char buf[MAX_DATA_SIZE];
	struct sockaddr_in serverAddr;
	int armFd = socket(AF_INET, SOCK_STREAM, 0);
}
