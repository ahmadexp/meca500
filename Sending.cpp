#include "Sending.h"

#include <chrono>
#include <condition_variable>
#include <thread>

#include "Exception.h"



namespace Meca500
{
    
    static std::condition_variable messageSentCondVar;
    static std::mutex messageSentMutex;
    static bool messageSent = false;
    static void SocketSendMessage(SocketInterface *socket, std::string message);

MessageSender::MessageSender(SocketInterface *socket)
{
	m_socket = socket;
}

    static void SocketSendMessage(SocketInterface *socket, std::string message)
    {
	socket->send(message);
	std::lock_guard<std::mutex> lock(messageSentMutex);
	messageSent = true;
	messageSentCondVar.notify_all();
    }

    static void Wait(int secondsToWait)
    {
	std::unique_lock<std::mutex> lock(messageSentMutex);
	if(messageSentCondVar.wait_for(lock,
				       std::chrono::seconds(secondsToWait),
				       []{return messageSent == true;}) == false) {
	    throw(Meca500::Exception("Sending message timed out!"));
	}

    }
    
    void MessageSender::SendMessage(std::string message, int secondsToWait)
    {
	std::thread sendThread(SocketSendMessage, m_socket, message);
	std::thread waitThread(Wait, secondsToWait);
	waitThread.join();
	sendThread.join();
   }

}

