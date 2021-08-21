interface i1
{
	void f1();
}
interface i2
{
	void f2();
}
class A implements i1,i2
{
	public void f1()
	{ }
	public void f2()
	{ }
	public void f3()
	{ }
}
class Example
{
	public static void main(String[] args)
	{
		A obj=new A();
		obj.f1();
		obj.f2();
		obj.f3();

	/*  
		I1 obj = new A();
		obj.f1(); // Correct
		obj.f2(); // Wrong
		obj.f3(); // Wrong
	*/
	}
}