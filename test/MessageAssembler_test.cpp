#include <gtest/gtest.h>
#include "MessageAssembler.h"
#include "Exception.h"

TEST(Meca500MessageAssembler, DetectsIfCommandNotKnown)
{
	ASSERT_FALSE(Meca500::IsKnownCommand("someCommand"));
}

TEST(Meca500MessageAssembler, DetectsIfCommandIsKnown)
{
	ASSERT_TRUE(Meca500::IsKnownCommand("ActivateRobot"));
}

TEST(Meca500MessageAssembler, AssembleMessageThrowsExceptionIfCommandNotKnown)
{
	bool exceptionThrown = false;
	try
	{
		Meca500::AssembleMessage("SomeCommand");
	}
	catch(Meca500::Exception e)
	{
		ASSERT_STREQ("ERROR: Command not known.", e.what());
		exceptionThrown = true;
	}
	ASSERT_TRUE(exceptionThrown);
}
