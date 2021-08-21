class Cars
{
	private int speed,price;
	public void setspeed(int s)
	{ speed = s; }
	public void setprice(int p)
	{ price = p; }
	public int getspeed()
	{ return speed; }
	public int getprice()
	{ return price; }
}

class Sportscar extends Cars
{
	private int booster;
	public void setbooster(int b)
	{ booster = b; }
	public int getbooster()
	{ return booster; }
}

public class Car
{
	public static void main(String[] args)
	{
		Sportscar obj = new Sportscar();
		obj.setspeed(360);
		obj.setprice(100000000);
		obj.setbooster(180);
		System.out.println("Speed : "+obj.getspeed());
		System.out.println("Price : "+obj.getprice());
		System.out.println("Booster : "+obj.getbooster());
	}
}