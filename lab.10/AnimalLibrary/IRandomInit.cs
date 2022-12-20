using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AnimalLibrary
{
	public interface IRandomInit
	{
		void RandomInit(Random rnd, Random rnd2);
		void RandomInit(Random rnd, Random rnd2, Random rnd3);
		void Print();
	}
}
