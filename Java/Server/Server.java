
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server extends ServerData {
	private Socket socket;

	public Socket getSocket() {
		return socket;
	}

	public void setSocket(Socket socket) {
		this.socket = socket;
	}

	public void Run() {
		try{
			ServerSocket serverSocket = new ServerSocket(port);
             while(true) {
        	 socket = serverSocket.accept();
        	 dataInputStream();
        	 dataOutputStream();
             }
	    }catch(IOException e) {
	    	System.out.println(e.toString());
	    }
	}

	public void dataInputStream( ) {
		try {
		InputStream inputStream_data = socket.getInputStream();
        byte[] receiveBuffer=new byte[100];
        inputStream_data.read(receiveBuffer);
    	System.out.println("server input "+new String(receiveBuffer));
		}
		 catch (IOException e) {
  			// TODO Auto-generated catch block
  			e.printStackTrace();
  		}
	}


	public void dataOutputStream( ) {
		OutputStream outputStream_data;
			try {
					outputStream_data = socket.getOutputStream();
					String sendDataString="client hi";
	              outputStream_data.write(sendDataString.getBytes());

			}
	      catch (IOException e) {
	      	// TODO Auto-generated catch block
	      	e.printStackTrace();
	      }
	}

}
