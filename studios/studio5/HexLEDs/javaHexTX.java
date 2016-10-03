package studio5.HexLEDs;

import studio4.SerialComm; //import this stuff below?
import java.io.BufferedReader;
import java.io.InputStream;
import assign4.ViewInputStream;

public class javaHexTX {
	
	public static void main(String[] args) {
	}
	
	public static void InputStreamReader(){
		BufferedReader sys =  new BufferedReader( new InputStreamReader(System.in));
		System.out.print(sys.read());
	}
}
