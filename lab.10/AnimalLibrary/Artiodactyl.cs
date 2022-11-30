using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AnimalLibrary
{
	public class Artiodactyl : Mammal, ICloneable
	{
		protected double hoofSize;
		public double HoofSize
		{
			get { return hoofSize; }
			set
			{
				if (value <= 0)
					Console.WriteLine("Размер копыта не может быть меньше или равен нулю");
				else
					hoofSize = value;
			}
		}
		public Artiodactyl()
		{
			HoofSize = 1;
		}
		public Artiodactyl(string name_) : base(name_)
		{
			HoofSize = 1;
		}
		public Artiodactyl(string name_, double weight_) : base(name_, weight_)
		{
			HoofSize = 1;
		}
		public Artiodactyl(string name_, double weight_, double hairLength_)
		: base(name_, weight_, hairLength_)
		{
			HoofSize = 1;
		}
		public Artiodactyl(string name_, double weight_, double hairLength_, double hoofSize_)
		: base(name_, weight_, hairLength_)
		{
			HoofSize = hoofSize_;
		}
		public Artiodactyl ShallowCopy()
		{
			return (Artiodactyl)this.MemberwiseClone();
		}
		public object Clone()
		{
			return new Artiodactyl("Клон " + this.name, this.weight, this.hairLength, this.hoofSize);
		}
		public override void Print()
		{
			Console.WriteLine($"Парнокопытное по имени {Name}, весом {Weight}, с длиной шерсти {HairLength}, c размером копыта {HoofSize} ");
		}
		public void RandomInit()
		{
			Random rnd = new Random();
			int i = rnd.Next(0, names.Length);
			int w = rnd.Next(1, 50);
			int s = rnd.Next(1, 100);
			int h = rnd.Next(1, 50);
			Name = names[i];
			Weight = w;
			HairLength = s;
			HoofSize = h;
		}
	}
}
