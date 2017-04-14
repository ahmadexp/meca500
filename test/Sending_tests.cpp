#include <gtest/gtest.h>

#include "Sending.h"
#include "MessageAssembler.h"
#include "Exception.h"
TEST(Meca500Sending, ThrowsErrorIfTimeout)
{
	bool exceptionThrown = false;
	try
	{
		Meca500::SendMessage(Meca500::AssembleMessage("ActivateRobot"));
	}
	catch(Meca500::Exception e){
		ASSERT_STREQ("ERROR: SendMessage timed out.", e.what());
		exceptionThrown = true;
	}
	ASSERT_TRUE(exceptionThrown);
}
