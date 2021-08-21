public class WrapperClass
{
	public static void main(String[] args)
	{
		// Valueof() 
		Integer i1 = Integer.valueof("123");
		Double d1 = Double.valueof("123.456");

		// ParseXxx()
		int x = Integer.parseInt("123");
		double x = Double.parseDouble("123");

		//xxxValue()
		int c = i1.intValue();
		double d = d1.doubleValue();
	}
}