using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AnimalLibrary
{
	public class Animal :  IRandomInit, ICloneable
	{
		public static string[] names = { "James", "Maria", "Kate", "Nick", "John", "Sofy", "Rufy", "Max", "Niko" };
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
		public void WrongPrint()
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
        public virtual object Clone()
        {
            return new Animal(Name, Weight);
        }
        public void RandomInit(Random rnd, Random rnd2, Random rnd3)
        {
			
        }
		public void RandomInit(Random rnd, Random rnd2)
		{
			//Random rnd = new Random();
			//Random rnd2 = new Random(21);
			int i = rnd.Next(0, names.Length);
			int w = rnd2.Next(1, 1000);
			Name = names[i];
			Weight = w;
		}
        public override string ToString()
        {
            return $"Animal(Name={Name}, Weight={Weight})";
        }
		public override bool Equals(object obj)
		{
			bool result = false;

			if (obj is Animal animal)
			{
				result = (name == animal.Name)
					  && (weight == animal.Weight);
			}

			return result;
		}

	}

}
