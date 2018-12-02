import java.rmi.*;  
import java.rmi.server.*;  
public class AdderRemote extends UnicastRemoteObject implements Adder{  
	AdderRemote()throws RemoteException{  
		super();  
	}  
	public int add(int x, int y){
		return x + y;
	}

	public int mult(int x, int y) throws RemoteException {
		return x * y;
	}

	public String hello() throws RemoteException {
		return "ohai there random stranger";
	}  
}  