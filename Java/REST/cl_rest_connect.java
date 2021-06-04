package REST;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.util.LinkedHashMap;
import java.util.Map;

public class cl_rest_connect {
	private URL url;
	StringBuilder postData;
	byte[] postDataBytes;
	Map<String,Object> params;
	HttpURLConnection m_connection;
	final String url_link="주소";
	BufferedReader rest_recv_data;


	private void fn_data_insert() {
		params = new LinkedHashMap<>();
		params.put("Key", "Value");
	}

	private boolean fn_create_post_data() throws IOException {
		 postData = new StringBuilder();
		    for(Map.Entry<String,Object> param : params.entrySet()) {
	            if(postData.length() != 0) postData.append('&');
	            postData.append(URLEncoder.encode(param.getKey(), "UTF-8"));
	            postData.append('=');
	            postData.append(URLEncoder.encode(String.valueOf(param.getValue()), "UTF-8"));
	        }

		    postDataBytes = postData.toString().getBytes("UTF-8");
		    return true;
	}


	private boolean fn_connect() throws IOException{
		m_connection = (HttpURLConnection)url.openConnection();
	    m_connection.setRequestMethod("POST");
	    m_connection.setRequestProperty("Content-Length", String.valueOf(postDataBytes.length));
	    m_connection.setDoOutput(true);
	    m_connection.getOutputStream().write(postDataBytes);
        rest_recv_data = new BufferedReader(new InputStreamReader(m_connection.getInputStream(), "UTF-8"));
        return true;
	}

	public void fn_run() throws IOException {
		url = new URL(url_link);
		fn_data_insert();
		fn_create_post_data();
		fn_connect();

        String inputLine;
        while((inputLine = rest_recv_data.readLine()) != null) {
            System.out.println("[Changun] class : cl_rest_connect , func : fn_connect , data : "+inputLine);
        }

        rest_recv_data.close();
	}
}
