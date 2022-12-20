using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace AnimalLibrary
{
	public class Bird : Animal, ICloneable, IRandomInit
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
		public void WrongPrint()
		{
			Console.WriteLine($"Птица по имени {Name}, весом {Weight}, с размером крыла {wingSize} ");
		}
		public Bird ShallowCopy() //поверхностное копирование
		{
			return (Bird)this.MemberwiseClone();
		}
        public object Clone()
        {
            return new Bird(Name, Weight, WingSize);
        }
        public void RandomInit(Random rnd, Random rnd2, Random rnd3)
		{
			//Random rnd = new Random();
			//Random rnd2 = new Random(100);
			//Random rnd3 = new Random(43321);
			int i = rnd.Next(0, names.Length);
			int w = rnd2.Next(1, 5000);
			int s = rnd3.Next(1, 100);
			Name = names[i];
			Weight = w;
			WingSize = s;
		}
		public Animal BaseAnimal
		{
			get
			{
				return new Animal (Name, Weight);
			}
		}
        public override string ToString()
        {
            return $"Bird(Name={Name}, Weight={Weight}, WingSize={WingSize})";
        }
		public override bool Equals(object obj)
		{
			bool result = false;

			if (obj is Bird animal)
			{
				result = (name == animal.Name)
					  && (weight == animal.Weight)
					  && (wingSize == animal.WingSize);
			}

			return result;
		}
	}
}
