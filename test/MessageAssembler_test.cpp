#include <gtest/gtest.h>
#include "MessageAssembler.h"

TEST(Meca500Messaging, DetectsIfCommandNotKnown)
{
	ASSERT_FALSE(Meca500::IsKnownCommand("someCommand"));
}

TEST(Meca500Messaging, DetectsIfCommandIsKnown)
{
	ASSERT_TRUE(Meca500::IsKnownCommand("ActivateRobot"));
}
