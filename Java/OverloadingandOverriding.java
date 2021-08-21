class One
{
	public void fun(int n) { System.out.println("Class : One"); }
}

class Two extends One
{
	public void fun(int n,int m) { System.out.println("Class : Two"); } // Overloading
	public void fun(int n) { System.out.println("Class : Two"); }       // Overriding
}

public class OverloadingandOverriding
{
	public static void main(String[] args)
	{
		Two obj = new Two();
		obj.fun(6);
		obj.fun(6,6);
	}
}
