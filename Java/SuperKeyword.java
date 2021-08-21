class A
{
	int  x;
	public void fun()
	{ }
}

class B extends A
{
	int z;
	public void fun()
	{
		super.fun(); 
	}
	public void fun2()
	{
		z=1;
		this.z=2;
		super.z=3;
	}
}

public class SuperKeyword
{
	public static void main(String[] args)
	{
		B obj = new B();
		obj.fun();
	}
}