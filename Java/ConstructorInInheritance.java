class A
{
	int a;
	public A(int x)
	{
		a=x;
		System.out.println("A");
	}
}

class B extends A
{
	int b;
	public B()
	{
		super(6);   // We can write this() also here. 
		System.out.println("B");
	}
}
public class ConstructorInInheritance
{
	public static void main(String args[])
	{
		B obj = new B();
	}
}
