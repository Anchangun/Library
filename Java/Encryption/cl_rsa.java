package Test;

import java.security.InvalidKeyException;
import java.security.KeyFactory;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.SecureRandom;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;
import java.util.Base64;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException; 


public class cl_rsa {
	private String m_public_key;
	private String m_private_key;
	private SecureRandom m_secure_random;
	private KeyPair m_key_pair;

	private final int key_size = 512;
	public cl_rsa()throws NoSuchAlgorithmException, InvalidKeySpecException{
		create_key();
	}
	
	private void create_key() throws NoSuchAlgorithmException{
		m_secure_random = new SecureRandom();
        KeyPairGenerator key_pair_generator = KeyPairGenerator.getInstance("RSA");
        key_pair_generator.initialize(key_size, m_secure_random);
        m_key_pair = key_pair_generator.genKeyPair();
        fn_create_public_key();
        fn_create_private_key();
	}
	
	private void fn_create_private_key() {
		PrivateKey private_key = m_key_pair.getPrivate();
	    m_private_key = Base64.getEncoder().encodeToString(private_key.getEncoded());
	}
	private void fn_create_public_key() {
		PublicKey public_key = m_key_pair.getPublic();
		m_public_key = Base64.getEncoder().encodeToString(public_key.getEncoded());
	}
	public String get_public_key() {
		return m_public_key;
	}
	public String get_private_key() {
		return m_private_key;
	}
 
	
	
	private PublicKey fn_plain_to_public(String public_key) throws NoSuchAlgorithmException, InvalidKeySpecException {
        KeyFactory key_factory = KeyFactory.getInstance("RSA");
        byte[] bytePublicKey = Base64.getDecoder().decode(public_key.getBytes());
        X509EncodedKeySpec publicKeySpec = new X509EncodedKeySpec(bytePublicKey);
        PublicKey publicKey = key_factory.generatePublic(publicKeySpec);
        return publicKey;
	}
	private Cipher fn_public_to_encode(PublicKey public_key) throws InvalidKeyException, NoSuchAlgorithmException, NoSuchPaddingException {
		 Cipher cipher = Cipher.getInstance("RSA");
         cipher.init(Cipher.ENCRYPT_MODE, public_key);
		return cipher;
	}
	private String fn_plain_to_encode(Cipher cipher,String plain_data) throws IllegalBlockSizeException, BadPaddingException {
		byte[] byteEncryptedData = cipher.doFinal(plain_data.getBytes());
		plain_data = Base64.getEncoder().encodeToString(byteEncryptedData);
		return plain_data;
	}
	//
    public String fn_encoding(String plain_data, String public_key) {
        String t_encode_data = null;
        try {
        	PublicKey t_publie_key=fn_plain_to_public(public_key);
        	Cipher t_cipher=fn_public_to_encode(t_publie_key);
        	t_encode_data=fn_plain_to_encode(t_cipher,plain_data);
           
        } catch (Exception e) {
            e.printStackTrace();
        }
        return t_encode_data;
    }

    private PrivateKey fn_plain_to_private(String private_key) throws NoSuchAlgorithmException, InvalidKeySpecException {
	    	KeyFactory keyFactory = KeyFactory.getInstance("RSA");
	        byte[] bytePrivateKey = Base64.getDecoder().decode(private_key.getBytes());
	        PKCS8EncodedKeySpec privateKeySpec = new PKCS8EncodedKeySpec(bytePrivateKey);
	        PrivateKey privateKey = keyFactory.generatePrivate(privateKeySpec);
        return privateKey;
    }
    private Cipher fn_private_to_encode(PrivateKey private_key) throws InvalidKeyException, NoSuchAlgorithmException, NoSuchPaddingException {
    	Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.DECRYPT_MODE, private_key);
        return cipher;
    }
    private String fn_encoder_to_plain(Cipher cipher, String encode_data) throws IllegalBlockSizeException, BadPaddingException {
    	String t_decode_data=null;
    	byte[] byteEncryptedData = Base64.getDecoder().decode(encode_data.getBytes());
        byte[] byteDecryptedData = cipher.doFinal(byteEncryptedData);
     
        t_decode_data = new String(byteDecryptedData);
        return t_decode_data;
    }
    
    public String fn_decoding(String encode_data, String private_key) {
        String t_decode_data = null;
        try {
         
            PrivateKey t_private_key =fn_plain_to_private(private_key);
           
            Cipher t_cipher = fn_private_to_encode(t_private_key);
  
            t_decode_data=fn_encoder_to_plain(t_cipher,encode_data);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return t_decode_data;
    }
	
}
