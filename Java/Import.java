package packageone;
import packagetwo.Student;
public class Import
{
	public static void main(String[] args)
	{
		Student obj = new Student();
		obj.setname("Akhil");
		obj.setrollno(07);
		obj.showname();
		obj.showrollno();
	}
}