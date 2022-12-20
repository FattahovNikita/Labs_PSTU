using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AnimalLibrary
{
    public class TestCollections
    {
        public List<string> stringList;
        public List<Animal> animalList;
        public SortedDictionary<Animal, Bird> AnimalBirdDictionary;
        public SortedDictionary<string, Bird> StringBirdDictionary;
        public Bird[] array;

        public TestCollections()
        {
            stringList = new List<string>();
            animalList = new List<Animal>();
            AnimalBirdDictionary = new SortedDictionary<Animal, Bird>(new AnimalComparer());
            StringBirdDictionary = new SortedDictionary<string, Bird>();
        }

        public void RandomInit(int countObjects)
        {
            Bird bird;
            array = new Bird[countObjects];
            Random rnd = new Random();
            Random rnd2 = new Random();
            Random rnd3 = new Random();

            for (int i = 0; i < countObjects; ++i)
            {
                bird = new Bird();
                bool factor;
                do
                {
                    bird.RandomInit(rnd, rnd2, rnd3);
                    if (StringBirdDictionary.ContainsKey(bird.BaseAnimal.ToString()))
                    {
                        factor = false;
                    }
                    else
                    {
                        StringBirdDictionary.Add(bird.BaseAnimal.ToString(), bird);
                        factor = true;
                    }
                }
                while (!factor);

                array[i] = bird;
                stringList.Add(bird.BaseAnimal.ToString());
                animalList.Add(bird.BaseAnimal);
                AnimalBirdDictionary.Add(bird.BaseAnimal, bird);

            }
        }
    }
    }
