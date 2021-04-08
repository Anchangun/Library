package Server;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class cl_tcp_server implements Runnable{
	private Socket client;
	private OutputStream outputStream_data;
	private InputStream inputStream_data;
	
	cl_tcp_server(Socket client){
		this.client=client;
	}
	
	@Override
	public void run() {
		System.out.println("[Changun] class : cl_tcp_server_ ,func : run, data : start");
		fn_input_data();
		fn_output_data("test");
	}

	/**
	 * @author Changun
	 * @brief Data 수신
	 * */
	private void fn_input_data( ) {
		try {
			inputStream_data = client.getInputStream();
	        byte[] receiveBuffer=new byte[100];
	        inputStream_data.read(receiveBuffer);
	    	System.out.println("server input "+new String(receiveBuffer));
		}
		 catch (IOException e) {
  			// TODO Auto-generated catch block
  			e.printStackTrace();
  		}
	}
	
	/**
	 * @author Changun
	 * @brief Data 송신
	 * 
	 * */
	public void fn_output_data(String output_data) {
			try {
					try {
						Thread.sleep(100000);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					outputStream_data = client.getOutputStream();
					outputStream_data.write(output_data.getBytes());
			}
	      catch (IOException e) {
	      	// TODO Auto-generated catch block
	      	e.printStackTrace();
	      }
	}
}
