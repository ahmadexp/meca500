#include "SocketInterface.h"
#include "Socket_Fake.h"
#include "Exception.h"

#include <chrono>
#include <thread>

Socket_Fake::Socket_Fake()
{
}

void Socket_Fake::send(std::string message)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

