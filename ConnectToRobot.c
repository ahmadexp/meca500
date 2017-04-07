#include <libsocket/libinetsocket.h>
#include <sys/fcntl.h>
#include <sys/time.h>
#include <unistd.h>
static const char *MECA_IP="192.168.0.100";
static const char *MECA_PORT="10000";
static const char BUFFER_SIZE=46;
int ConnectToRobot()
{
	int sockfd, bytes, ret;
	char buf[BUFFER_SIZE];

	sockfd = create_inet_stream_socket(MECA_IP, MECA_PORT, LIBSOCKET_IPv4, 0);

	if(sockfd < 0) {
		perror(0);
		exit(1);
	}

	struct timeval tv;
	fd_set readfds;
	
	tv.tv_sec=2;
	tv.tv_usec=0;

	FD_ZERO(&readfds);
	FD_SET(sockfd, &readfds);

	select(sockfd + 1, &readfds, NULL, NULL, &tv);
	
	if(FD_ISSET(sockfd, &readfds)) {
		bytes = read(sockfd, buf, BUFFER_SIZE-1);
	}
	else {
		printf("Timed out");
	}
		

	printf("bytes = %d\n", bytes);

	if(bytes<0){
		perror(0);
		exit(1);
}	printf("bytes = %d\n", bytes);
	printf("buf = %s", buf);
	//return 0;
	ret = destroy_inet_socket(sockfd);
//	printf("%d",ret);
	//if(ret < 0) {
//		perror(0);
//		exit(1);
//	}

	return 0;	
}
