#include <libsocket/libinetsocket.h>

static const char *MECA_IP="192.168.0.100";
static const char *MECA_PORT="10000";

int ConnectToRobot()
{
	int sockfd, bytes, ret;
	char buf[32];

	buf[31] = 0;
	
	sockfd = create_inet_stream_socket(MECA_IP, MECA_PORT, LIBSOCKET_IPv4, 0);

	if(sockfd < 0) {
		return -1;
	}

	while(0 < (bytes = read(sockfd, buf, 31))) {
		write(1,buf,bytes);
	}		

	printf("bytes = %s", bytes);

	return 0;	
}
