using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace AnimalLibrary
{
	public class Bird : Animal, ICloneable
	{
		protected double wingSize;
		public double WingSize
		{
			get { return wingSize; }
			set
			{
				if (value <= 0)
					Console.WriteLine("Размер крыла не может быть меньше или равен нулю");
				else
					wingSize = value;
			}
		}
		public Bird()
		{
			WingSize = 1;
		}
		public Bird(string name_) : base(name_)
		{
			WingSize = 1;
		}
		public Bird(string name_, double weight_) : base(name_, weight_)
		{
			WingSize = 1;
		}
		public Bird(string name_, double weight_, double wingSize_)
		: base(name_, weight_)
		{
			WingSize = wingSize_;
		}
		public override void Print()
		{
			Console.WriteLine($"Птица по имени {Name}, весом {Weight}, с размером крыла {wingSize} ");
		}
		public Bird ShallowCopy() //поверхностное копирование
		{
			return (Bird)this.MemberwiseClone();
		}
		public object Clone()
		{
			return new Bird("Клон " + this.name, this.weight, this.wingSize);
		}
		public void RandomInit()
		{
			Random rnd = new Random();
			int i = rnd.Next(0, names.Length);
			int w = rnd.Next(1, 50);
			int s = rnd.Next(1, 100);
			Name = names[i];
			Weight = w;
			WingSize = s;
		}
	}
}
