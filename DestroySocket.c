
#include <libsocket/libinetsocket.h>

int DestroySocket(int socket)
{
	int ret = destroy_inet_socket(socket);
	return ret;
}
