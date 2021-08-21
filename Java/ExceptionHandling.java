public class ExceptionHandling
{
	public static void main(String[] args)
	{
		try
		{
			System.out.println(1/0);
		}
		catch(Exception e)
		{
			System.out.println(e.getMessage());
		}
		finally
		{
			System.out.println("Hahaha, I am superior than others.");
		}
	} 
}