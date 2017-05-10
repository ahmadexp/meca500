import java.io.*;
import java.net.*;
import java.util.Arrays;

class meca500{
    public static void main(String[] args) {
String hostName = "192.168.0.100";
int portNumber = 10000;

Socket robotSocket = null;
DataOutputStream out = null;
DataInputStream in = null;
    byte[] response = new byte[100];
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

 try{
	System.out.println("Starting to read");

	in.read(response);
	System.out.println(Arrays.toString(response));
	
    }catch(IOException e){System.err.println("Couldn't get response");}
System.out.println("Activating robot");
try{
    out.writeBytes("ActivateRobot<\0>");
}catch(IOException e){System.err.println("Couldn't write to robot");}

    System.out.println("ActivateRobot SENT");

    int c = -1;

    try{
	System.out.println("Starting to read");

	in.read(response);
	System.out.println(Arrays.toString(response));
	
    }catch(IOException e){System.err.println("Couldn't get response");}
    System.out.println(response);
    try{
    robotSocket.close();
    }catch(IOException e){System.err.println("Couldn't close robot");}
    }
}

    
    
