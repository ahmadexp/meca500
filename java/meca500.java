import java.io.*;
import java.net.*;

class meca500{
    public static void main(String[] args) {
String hostName = "192.168.0.100";
int portNumber = 10000;

Socket robotSocket = null;
PrintWriter out = null;
BufferedReader in = null;

try {
     robotSocket = new Socket();
     SocketAddress sockaddr = new InetSocketAddress(hostName, portNumber);
     robotSocket.connect(sockaddr, 3000);
     out = new PrintWriter(robotSocket.getOutputStream(), true);
     in = new BufferedReader(new InputStreamReader(robotSocket.getInputStream()));
}catch(UnknownHostException e){System.err.println("Couldn't find host");}
catch(IOException e) {
	System.err.println("Couldn't get I/O for robot");
    }
    out.println("ActivateRobot");
    try{
System.out.println(in.readLine());
    }catch(IOException e){System.err.println("Couldn't read line from robot");}
        }
}

    
    
