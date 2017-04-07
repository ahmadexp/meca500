
#include <libsocket/libinetsocket.h>

#include "DestroySocket.h"

int DestroySocket(int socket)
{
	int ret = destroy_inet_socket(socket);
	return ret;
}
