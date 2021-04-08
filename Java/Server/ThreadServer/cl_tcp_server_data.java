package Server;

import java.net.ServerSocket;
import java.net.Socket;

/**
 * This class has the basic data of the WBMS server.
 * @author changun
 * @see Server.cl_tcp_single_server
 * */
public class cl_tcp_server_data {
	protected Socket socket;
	protected ServerSocket server_socket;
	protected int port = 1234;
}
