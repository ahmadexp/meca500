import java.io.*;
import java.net.*;
import java.util.Arrays;

class meca500{
static DataOutputStream out = null;
static DataInputStream in = null; 
static Socket robotSocket = null;

    public static void SetupSocket(){
	String hostName = "192.168.0.100";
	int portNumber = 10000;
	try {
	    robotSocket = new Socket();
	    SocketAddress sockaddr = new InetSocketAddress(hostName, portNumber);
	    robotSocket.connect(sockaddr, 3000);
	    out = new DataOutputStream(robotSocket.getOutputStream());
	    in = new DataInputStream(robotSocket.getInputStream());
	}catch(UnknownHostException e){System.err.println("Couldn't find host");}
	catch(IOException e) {
	    System.err.println("Couldn't get I/O for robot");
	}

    }

    public static void CloseSocket(Socket aSocket){
	try{
	    robotSocket.close();
	}catch(IOException e){System.err.println("Couldn't close socket");}
    }
    
    public static void SendMessage(String message){
	message += "\0";
	try{
	    out.flush();
	    System.out.println("Sending:"+message);
	    out.writeBytes(message);
	}catch(IOException e){
	    System.err.println("Couldn't write to robot");
	}
    }

    public static void ReadMessage(){
	byte[] response = new byte[100];
        try{
	    in.read(response);
	    String responseString = new String(response,"UTF-8");
	    System.out.println(responseString);
	
	}catch(IOException e){System.err.println("Couldn't get response");}
    }

    public static void Wait(int milliseconds){
	try{
	    Thread.sleep(5000);
	}catch(InterruptedException e){ System.out.println("Interrupted sleep");}
    }
    
    public static void main(String[] args) {
	SetupSocket();
	ReadMessage();
	SendMessage("ActivateRobot");
	ReadMessage();
	Wait(5000);
	SendMessage("DeactivateRobot");
	ReadMessage();
   
    }
}
    
    
