package studio4;

import gnu.io.NoSuchPortException;
import java.io.InputStream;
import java.io.*;

public class SerialTestInput {

	public static void main(String[] args) {
		
		SerialComm port = new SerialComm();
		
	
			try {
				port.connect("COM4");
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	
	while(true){
	port.getInputStream().available();
	port.getInputStream().read();
	System.out.print(port.getInputStream().read());
		}
	}
	
}


