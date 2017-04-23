#include "Sending.h"

#include <chrono>
#include <condition_variable>
#include <exception>
#include <thread>

#include "Exception.h"



namespace Meca500
{
    
    static std::condition_variable messageSentCondVar;
    static std::mutex messageSentMutex;
    static bool messageSent = false;
    static std::exception_ptr threadException = nullptr;
    static void SocketSendMessage(SocketInterface *socket, std::string message);
    static void WaitOnMessageSentVar(int secondsToWait);

MessageSender::MessageSender(SocketInterface *socket)
{
	m_socket = socket;
}

    static void SocketSendMessage(SocketInterface *socket, std::string message)
    {
	socket->write(message);
	std::lock_guard<std::mutex> lock(messageSentMutex);
	messageSent = true;
	messageSentCondVar.notify_all();
    }

    static void WaitOnMessageSentVar(int secondsToWait)
    {
	std::unique_lock<std::mutex> lock(messageSentMutex);
	try
	{
	    if(messageSentCondVar.wait_for(lock,
					   std::chrono::seconds(secondsToWait),
					   []{return messageSent == true;}) == false) {
		throw Meca500::Exception("ERROR: Sending message timed out.");
	    }
	}
	catch(...)
	{
	    threadException = std::current_exception();
	}

    }
    
    void MessageSender::SendMessageWithTimeout(std::string message, int secondsToWait)
    {

	std::thread sendThread(SocketSendMessage, m_socket, message);
	std::thread waitThread(WaitOnMessageSentVar, secondsToWait);
	waitThread.join();
	sendThread.join();

	if(threadException) 
	{
	    std::rethrow_exception(threadException);
	}
   }

}

