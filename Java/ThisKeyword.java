class Box
{
	private int l,b,h;
	public void setDimension(int l,int b,int h) // Instance Member Function
	{
		this.l=l;
		this.b=b;
		this.h=h;
	}
	public void sendBox()
	{
		GiftTaker gf = new GiftTaker();
		gf.acceptGift(this);            // As we cannot passed b( Object) here
	}
}
public class ThisKeyword
{
	public static void main(String[] args) // Static Member Function
	{
		Box b = new Box();
		b.setDimension(36,72,144);
	}
} 