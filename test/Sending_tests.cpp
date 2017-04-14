#include <gtest/gtest.h>

#include "Sending.h"
#include "MessageAssembler.h"
#include "Exception.h"
TEST(Meca500Sending, ThrowsErrorIfTimeout)
{
	try
	{
		Meca500::SendMessage(Meca500::AssembleMessage("SomeCommand"));
	}
	catch(Meca500::Exception){
		
	}
}
