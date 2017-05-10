import java.io.*;
import java.net.*;
import java.util.Arrays;

class meca500{
static DataOutputStream out = null;
static DataInputStream in = null; 

    
    public static void SendMessage(String message){
	message += "<\0>";
	try{
	    out.writeBytes("ActivateRobot<\0>");
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
    
    public static void main(String[] args) {
String hostName = "192.168.0.100";
int portNumber = 10000;

Socket robotSocket = null;
    
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
ReadMessage();
SendMessage("ActivateRobot");
ReadMessage();
    try{
    robotSocket.close();
    }catch(IOException e){System.err.println("Couldn't close robot");}
    }
}

    
    
