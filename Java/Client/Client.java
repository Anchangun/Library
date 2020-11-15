import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class Client extends ClientData {
	private String input_msg;
	private Socket client_socket;

	public String getInput_msg() {
		return input_msg;
	}

	public void socketCreate() {
		try {
			client_socket=new Socket(string_ip,int_port);
		//	System.out.println("client test");
	 	} catch (IOException e) {
		// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void socketDelete() {
		try {
			client_socket.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public void dataInputStream() {

		if(client_socket!=null) {
		    try {

				InputStream input_stream_data = client_socket.getInputStream();
				byte[] receive_buffer=new byte[5000];
				input_stream_data.read(receive_buffer);
				input_msg=new String(receive_buffer);
				System.out.println(input_msg);
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

	}
	public void dataOutPutStream(String output_msg) {
		OutputStream output_stream_data;
		try {
			output_stream_data=client_socket.getOutputStream();
			output_stream_data.write(output_msg.getBytes());

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
