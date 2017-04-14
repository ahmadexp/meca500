#include <gtest/gtest.h>

#include "Sending.h"
#include "Messages.h"

TEST(Meca500Sending, ThrowsErrorIfTimeout)
{
	try
	{
		Meca500::Send(Meca500::GetMessage("SomeCommand"));
	}
	catch(){}
}
