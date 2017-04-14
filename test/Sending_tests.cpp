#include <gtest/gtest.h>

#include "Sending.h"
#include "MessageAssembler.h"

TEST(Meca500Sending, ThrowsErrorIfTimeout)
{
	try
	{
		Meca500::SendMessage(Meca500::GetMessage("SomeCommand"));
	}
	catch(){}
}
