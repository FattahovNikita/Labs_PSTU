using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AnimalLibrary
{
	public class AnimalComparer : IComparer<Animal>
	{
		public int Compare(Animal p1, Animal p2)
		{
			if (p1 is null || p2 is null)
				throw new ArgumentException("Некорректное значение параметра");
			return String.Compare(p1.Name, p2.Name);
		}
	}
}
