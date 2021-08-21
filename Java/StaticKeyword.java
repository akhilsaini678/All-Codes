// Instance function  or variable are those for which we need an object to call them.
// Static variable and function are those for which we don't need any object. They can be called by class name.
// Instance variable and function creates as new for every object.
// Static variable and function are only one for the whole class.

class Example
{
		int x; // Instance variable
		static int y; // Static member variable

		public void fun1() { System.out.println("Hello World"); } // Instance function
		public static void fun2() { System.out.println("Hello World"); } // Static member function

		static class Countries
		{
			public static String country = "India";
		}
}

public class StaticKeyword
{
	public static void main(String args[])
	{
		Example.y=5;
		Example.fun2();
		System.out.println( Example.Countries.country);
	}
}