#include <gtest/gtest.h>

#include "Sending.h"
#include "MessageAssembler.h"
#include "Exception.h"
#include "SocketInterface.h"
#include "Socket_Fake.h"

TEST(Meca500Sending, ThrowsErrorIfTimeout)
{
	bool exceptionThrown = false;
	Socket_Fake fakeSocket;
	Meca500::MessageSender sender(dynamic_cast<SocketInterface *>(&fakeSocket));
	try
	{
		sender.SendMessage(Meca500::AssembleMessage("ActivateRobot"));
	}
	catch(Meca500::Exception e){
		ASSERT_STREQ("ERROR: Sending message timed out.", e.what());
		exceptionThrown = true;
	}
	ASSERT_TRUE(exceptionThrown);
}
