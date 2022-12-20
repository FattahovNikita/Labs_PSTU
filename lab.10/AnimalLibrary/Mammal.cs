using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AnimalLibrary
{
	public class Mammal : Animal, ICloneable, IRandomInit
	{
		protected double hairLength;
		public double HairLength
		{
			get { return hairLength; }
			set
			{
				if (value < 0)
					Console.WriteLine("Длина шерсти не может быть меньше нуля");
				else
					hairLength = value;
			}
		}

		public Mammal()
		{
			HairLength = 1;
		}
		public Mammal(string name_) : base(name_)
		{
			HairLength = 1;
		}
		public Mammal(string name_, double weight_) : base(name_, weight_)
		{
			HairLength = 1;
		}
		public Mammal(string name_, double weight_, double hairLength_)
		: base(name_, weight_)
		{
			HairLength = hairLength_;
		}
		public override void Print()
		{
			Console.WriteLine($"Млекопитающее по имени {Name}, весом {Weight}, с длиной шерсти {HairLength} ");
		}
		public void WrongPrint()
		{
			Console.WriteLine($"Млекопитающее по имени {Name}, весом {Weight}, с длиной шерсти {HairLength} ");
		}
		public Mammal ShallowCopy()
		{
			return (Mammal)this.MemberwiseClone();
		}
		public object Clone()
		{
			return new Mammal("Клон " + this.name, this.weight, this.hairLength);
		}
		public void RandomInit()
		{
			Random rnd = new Random();
			int i = rnd.Next(0, names.Length);
			int w = rnd.Next(1, 50);
			int s = rnd.Next(1, 100);
			Name = names[i];
			Weight = w;
			HairLength = s;
		}
	}
}
