package Test;

import java.io.UnsupportedEncodingException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.security.spec.InvalidKeySpecException;

import javax.crypto.BadPaddingException;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;

public class cl_test_rsa {

	public static void main(String[] args) throws NoSuchAlgorithmException, InvalidKeySpecException, InvalidKeyException, NoSuchPaddingException, IllegalBlockSizeException, BadPaddingException, UnsupportedEncodingException {
		String ps="123", encode, decode;
		System.out.println(ps);
		cl_rsa m_rsa = new cl_rsa();
		System.out.println(m_rsa.get_public_key());
		System.out.println(m_rsa.get_private_key());
		encode=m_rsa.fn_encoding(ps,m_rsa.get_public_key());
		System.out.println(encode);
		decode=m_rsa.fn_decoding(encode,m_rsa.get_private_key());
		System.out.println(decode);
	}
}
