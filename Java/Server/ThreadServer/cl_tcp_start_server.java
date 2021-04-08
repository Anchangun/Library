package Server;

import java.io.IOException;
import java.net.ServerSocket;

public class cl_tcp_start_server extends cl_tcp_server_data{
	private boolean result=false;
	public boolean cl_run() {
	
		try {
			server_socket= new ServerSocket(port);
			while(true) {	
				result=true;
				socket=server_socket.accept();
				  Thread thread = new Thread(new cl_tcp_server(socket));
			      thread.start();
			}

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			result=false;
		}
		finally {
			try {
				server_socket.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				result=false;
				
			}
		}
		return result;
		
	}
}
