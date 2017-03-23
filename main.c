#include <libsocket/libinetsocket.h>

static const char *MECA_IP="192.168.0.100";
static const char *MECA_PORT="10000";

int main(int argc, char *argv[])
{
	int sockfd, ret, bytes;
	char request[128], buf[32];

	buf[31] = 0;
	
	ret = sockfd = create_inet_stream_socket(MECA_IP, MECA_PORT, LIBSOCKET_IPv4, 0);

	if(ret < 0) {
		perror(0);
		exit(1);
	}	

	return 0;	
}
