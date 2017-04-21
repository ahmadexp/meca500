
#include <libsocket/libinetsocket.h>

#include "DestroySocket.h"

int DestroySocket(int socket)
{
	return destroy_inet_socket(socket);
}
