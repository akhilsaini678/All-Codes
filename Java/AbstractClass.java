// Java Abstract Class are used to declare common characterstics of subclasses 
// It can only be used as a superclass
abstract class Person
{
	private String name;
	private int rollno;
	public void setname(String n)
	{
		name=n;
	};
	public void setrollno(int rn)
	{
		rollno=rn;
	}
}

class Student extends Person
{
}

class One
{
	public static void main(String[] args)
	{
		Student s = new Student();
		s.setname("Akhil")
		s.setrollno(07);
	}
}