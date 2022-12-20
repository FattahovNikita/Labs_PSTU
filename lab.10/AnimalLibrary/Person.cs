using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AnimalLibrary
{
	public class Person : IRandomInit
	{
		public static string[] names = { "James", "Maria", "Kate", "Nick", "John", "Sofy", "Rufy", "Max", "Niko" };
		protected string name;
		protected int age;
		public string Name
		{
			get { return name; }
			set { name = value; }
		}
		public int Age
		{
			get { return age; }
			set
			{
				if (value <= 0)
					Console.WriteLine("Возраст не может быть меньше или равен нулю");
				else
					age = value;
			}
		}
		public Person()
		{
			Name = "безымяный";
			Age = 25;
		}
		public Person(string name_)
		{
			Name = name_;
			Age = 25;
		}
		public Person(string name_, int age_)
		{
			Name = name_;
			Age = age_;
		}
		public void Print()
		{
			Console.WriteLine($"Человек {Name}, с возрастом {Age}");
		}
		public void RandomInit()
		{
			Random rnd = new Random();
			int i = rnd.Next(0, names.Length);
			int w = rnd.Next(1, 100);
			Name = names[i];
			Age = w;
		}
		public void RandomInit(Random rnd, Random rnd2, Random rnd3)
		{

		}
		public void RandomInit(Random rnd, Random rnd2)
		{

		}
	}
}
