public class ClassandObject
{
	public static void main(String[] args)
	{
		box box1 = new box();
		box1.setdimensions(6,6,6);
		box1.showdimensions(); 
	}
}

class box
{
	int length,breadth,height;
	public void setdimensions(int l,int b,int h)
	{
		length=l;
		breadth=b;
		height=h;
	}
	public void showdimensions()
	{
		System.out.println("L = "+length);
		System.out.println("B = "+breadth);
		System.out.println("H = "+height);
	}
}