using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AnimalLibrary
{
	public class Animal : IComparable<Animal>
	{
		public static String[] names = { "James", "Maria", "Kate", "Nick", "John", "Sofy", "Rufy", "Max", "Niko" };
		protected string name;
		protected double weight;
		public string Name
		{
			get { return name; }
			set { name = value; }
		}
		public double Weight
		{
			get { return weight; }
			set
			{
				if (value <= 0)
					Console.WriteLine("Вес не может быть меньше или равен нулю");
				else
					weight = value;
			}
		}
		public Animal()
		{
			Name = "безымяный";
			Weight = 1;
		}
		public Animal(string name_)
		{
			Name = name_;
			Weight = 1;
		}
		public Animal(string name_, double weight_)
		{
			Name = name_;
			Weight = weight_;
		}
		virtual public void Print()
		{
			Console.WriteLine($"Животное по имени {Name}, весом {Weight}");
		}
		public int CompareTo(Animal animal)
		{
			if (animal is null) throw new ArgumentException("Некорректное значение параметра");
			return Weight.CompareTo(animal.Weight);
		}
		public Animal ShallowCopy()
		{
			return (Animal)this.MemberwiseClone();
		}
		public object Clone()
		{
			return new Animal("Клон" + this.name, this.weight);
		}
		public void RandomInit()
		{
			Random rnd = new Random();
			int i = rnd.Next(0, names.Length);
			int w = rnd.Next(1, 100);
			Name = names[i];
			Weight = w;
		}
	}

}
