#include <gtest/gtest.h>

#include "Receiving.h"
#include "SocketInterface.h"
#include "Socket_Fake.h"

TEST(Meca500Receiving, ThrowsErrorIfTimeout)
{
    bool exceptionThrown = false;
    Socket_Fake fakeSocket;
    Meca500::ReceiveMessage(dynamic_cast<SocketInterface *>(&fakeSocket));
}
