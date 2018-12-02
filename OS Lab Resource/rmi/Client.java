import java.rmi.*;
import java.util.Scanner;  
public class Client{  
	public static void main(String args[]){  
		try{  
			Adder stub=(Adder)Naming.lookup("rmi://localhost:5000/sonoo"); 
			Scanner sc = new Scanner(System.in);
			int a = sc.nextInt();
			int b = sc.nextInt();
			System.out.println(stub.add(a, b));
			System.out.println(stub.mult(a, b));
			System.out.println(stub.hello());
		}catch(Exception e){}  
	}  
}  