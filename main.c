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

void *get_in_addr(struct sockaddr *sa)
{
	if(sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in *)sa)->sin_addr);
	}
	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

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

	for(p = servinfo; p != NULL; p = p->ai_next) {
		if((sockfd = socket(p->ai_family, p->ai_socktype,
		p->ai_protocol)) == -1) {
			perror("client: connect");
			continue;
		}
			
		if(connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("client: connect");
			continue;
		}
		
		break;
	}
	
	if(p == NULL) {
		fprintf(stderr, "client: failed to connect\n");
		return 2;
	}

	inet_ntop(p->ai_family, get_in_addr((struct sockaddr*)p->ai_addr),
		s, sizeof s);
	printf("client: connecting to %s\n", s);

	freeaddrinfo(servinfo);

	if((numbytes = recv(sockfd, buf, MAX_DATA_SIZE-1, 0)) == -1) {
		perror("recv");
		exit(1);
	}		

	buf[numbytes] = '\0';

	printf("client: received '%s'\n",buf);

	char *command = "MoveJointsDelta(-20,-20,-20,-20,-20,-20)";
	int sendNum = send(sockfd, command, strlen(command)+1, 0);
	printf("number of bytes sent = %d\n", sendNum);

	close(sockfd);

	return 0;

}
