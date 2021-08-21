final class Dummy // Now it cannot be extended
{
	public final void fun1() // Now it cannot be override
	{ }
}

class MoreDummy extends Dummy
{
	public void fun1()
	{ };
}

public class FinalKeyword
{
	private final int x;       // Final Instance Variable
	private final static int y; // Final Static Variable
	static 
	{
		y=6;
	}
	FinalKeyword(int y)
	{
		x=y;
	}
	public void fun()
	{
		final int k; // Final local variable
	}

	public static void main(String args[])
	{
		FinalKeyword obj = new FinalKeyword(10);
	}
}