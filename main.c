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
static const char *MECA_ARM_IP_ADDR = "192.168.0.100";
static const char *MECA_ARM_PORT = "10000";

int main(int argc, char *argv[])
{	
	int sockfd, numbytes, rv;
	char buf[MAX_DATA_SIZE];
	struct addrinfo hints, *servinfo, *p;
	char s[INET6_ADDRSTRLEN];

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;	

	if((rv = getaddrinfo(MECA_ARM_IP_ADDR,
		MECA_ARM_PORT,
		&hints,
		&servinfo)) !=0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	} 
	
	int armFd = socket(AF_INET, SOCK_STREAM, 0);
	

}
