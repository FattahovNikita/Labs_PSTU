using System;

public class Animal
{
	protected string name;
	public string Name
	{
		get { return name; }
		set { name = value; }
	}
	public Animal()
	{
		Name = "безымяный";
	}
	public Animal(string name_)
	{
		Name = name_;
	}
	virtual public void Print()
	{
		Console.WriteLine($"Животное по имени {Name}");
	}
	
}
