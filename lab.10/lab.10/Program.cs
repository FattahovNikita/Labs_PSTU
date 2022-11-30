using System;
using System.Collections.Generic;
using System.Text;
//using AnimalsLib;
using AnimalLibrary;

namespace lab._10
{
    class Program
    {
        static Animal[] zoo = { };
        static void Task()
        {
            int op;
            do
            {
                Animal animal;
                Bird bird;
                Mammal mammal;
                Artiodactyl arti;
                op = GetOperationStart();
                switch (op)
                {
                    case 1:
                        animal =  AnimalChoose();
                        if (animal!=null)
                            AddToArray(ref zoo, animal);
                        break;
                    case 2:
                        bird = BirdChoose();
                        if (bird != null)
                            AddToArray(ref zoo, bird);
                        break;
                    case 3:
                        mammal = MammalChoose();
                        if (mammal != null)
                            AddToArray(ref zoo, mammal);
                        break;
                    case 4:
                        arti = ArtioChoose();
                        if (arti != null)
                            AddToArray(ref zoo, arti);
                        break;
                    case 5:
                        if (!IsEmptyArr(zoo))
                            PrintArray(zoo);
                        break;
                    case 6:
                        Console.WriteLine($"Кол-во птиц в зоопарке - {BirdsAmount()}");
                        break;
                    case 7:
                        Console.WriteLine($"Средний вес зверей в зоопарке - {AverageWeight()}");
                        break;
                    case 8:
                        Console.WriteLine("Список имен всех зверей в зоопарке");
                        GetNames();
                        break;
                    case 9:
                        if (!IsEmptyArr(zoo))
                        {
                            Array.Sort(zoo);
                            Console.WriteLine("Массив отсортирован по весу");
                        }
                        break;
                    case 10:
                        if (!IsEmptyArr(zoo))
                        {
                            Array.Sort(zoo, new AnimalComparer());
                            Console.WriteLine("Массив отсортирован по именам");
                        }
                        break;
                    case 11:
                        Console.WriteLine("Введите кол-во элементов для добавления");
                        int size = ReadIntDigit();
                        RandomArray(ref zoo, size);
                        Console.WriteLine("Элементы добавлены");
                        break;
                    case 12:
                        Array.Resize(ref zoo, 0);
                        Console.WriteLine("Массив очищен");
                        break;
                    case 13:
                        Console.WriteLine("Копирование и клонирование");
                        CloneTask();
                        break;
                    default:
                        Console.WriteLine("Ошибка ввода операции, выберите операцию из списка");
                        break;
                }
                if (op == 0)
                    break;
            } while (true);
        }
        static void CloneTask()
        {
            int op;
            do
            {
                Animal animal;
                Animal copyAnimal;
                Animal cloneAnimal;
                Bird bird;
                Bird copyBird;
                Bird cloneBird;
                Mammal cloneMammal;
                Mammal copyMammal;
                Mammal mammal;
                Artiodactyl cloneArti;
                Artiodactyl copyArti;
                Artiodactyl arti;
                op = GetCloneStart();
                switch (op)
                {
                    case 1:
                        animal = AnimalChoose();
                        if (animal != null)
                        {
                            copyAnimal = animal.ShallowCopy();
                            Console.WriteLine("Копия объекта:");
                            copyAnimal.Print();
                            cloneAnimal = (Animal)animal.Clone();
                            Console.WriteLine("Клон объекта:");
                            cloneAnimal.Print();
                        }
                        break;
                    case 2:
                        bird = BirdChoose();
                        if (bird != null)
                        {
                            copyBird = bird.ShallowCopy();
                            Console.WriteLine("Копия объекта:");
                            copyBird.Print();
                            cloneBird = (Bird)bird.Clone();
                            Console.WriteLine("Клон объекта:");
                            cloneBird.Print();
                        }
                        break;
                    case 3:
                        mammal = MammalChoose();
                        if (mammal != null)
                        {
                            copyMammal = mammal.ShallowCopy();
                            Console.WriteLine("Копия объекта:");
                            copyMammal.Print();
                            cloneMammal = (Mammal)mammal.Clone();
                            Console.WriteLine("Клон объекта:");
                            cloneMammal.Print();
                        }
                        break;
                    case 4:
                        arti = ArtioChoose();
                        if (arti != null)
                        {
                            copyArti = arti.ShallowCopy();
                            Console.WriteLine("Копия объекта:");
                            copyArti.Print();
                            cloneArti = (Artiodactyl)arti.Clone();
                            Console.WriteLine("Клон объекта:");
                            cloneArti.Print();
                        }
                        break;
                    case 0:
                        break;
                    default:
                        Console.WriteLine("Ошибка ввода операции, выберите операцию из списка");
                        break;
                }
                if (op == 0)
                    break;
            } while (true);
        }
        static Animal AnimalChoose()
        {
            int op;
            do
            {
                op = GetCreationStart();
                Animal animal;
                string name;
                double weight;
                switch (op)
                {
                    case 1:
                        animal = new Animal();
                        Console.WriteLine("Объект создан");
                        return animal;
                        break;
                    case 2:
                        Console.Write("Введите имя:");
                        name = Console.ReadLine();
                        animal = new Animal(name);
                        Console.WriteLine("Объект создан");
                        return animal;
                        break;
                    case 3:
                        Console.Write("Введите имя:");
                        name = Console.ReadLine();
                        Console.Write("Введите вес:");
                        weight = ReadDoubleDigit();
                        animal = new Animal(name, weight);
                        Console.WriteLine("Объект создан");
                        return animal;
                        break;
                    case 0:
                        return null;
                        break;
                    default:
                        Console.WriteLine("Ошибка ввода операции, выберите операцию из списка");
                        return null;
                        break;

                }
                if (op == 0)
                    break;
            } while (true);
        }
        static Bird BirdChoose()
        {
            int op;
            do
            {
                op = GetCreationBirdStart();
                Bird animal;
                string name;
                double weight;
                double wingSize;
                switch (op)
                {
                    case 1:
                        animal = new Bird();
                        Console.WriteLine("Объект создан");
                        return animal;
                        break;
                    case 2:
                        Console.Write("Введите имя:");
                        name = Console.ReadLine();
                        animal = new Bird(name);
                        Console.WriteLine("Объект создан");
                        return animal;
                        break;
                    case 3:
                        Console.Write("Введите имя:");
                        name = Console.ReadLine();
                        Console.Write("Введите вес:");
                        weight = ReadDoubleDigit();
                        animal = new Bird(name, weight);
                        Console.WriteLine("Объект создан");
                        return animal;
                        break;
                    case 4:
                        Console.Write("Введите имя:");
                        name = Console.ReadLine();
                        Console.Write("Введите вес:");
                        weight = ReadDoubleDigit();
                        Console.Write("Введите размах крыльев:");
                        wingSize = ReadDoubleDigit();
                        animal = new Bird(name, weight, wingSize);
                        Console.WriteLine("Объект создан");
                        return animal;
                        break;
                    case 0:
                        return null;
                        break;
                    default:
                        Console.WriteLine("Ошибка ввода операции, выберите операцию из списка");
                        return null;
                        break;
                }
                if (op == 0)
                    break;
            } while (true);
        }
        static Mammal MammalChoose()
        {
            int op;
            do
            {
                op = GetCreationMammalStart();
                Mammal animal;
                string name;
                double weight;
                double wingSize;
                switch (op)
                {
                    case 1:
                        animal = new Mammal();
                        Console.WriteLine("Объект создан");
                        return animal;
                        break;
                    case 2:
                        Console.Write("Введите имя:");
                        name = Console.ReadLine();
                        animal = new Mammal(name);
                        Console.WriteLine("Объект создан");
                        return animal;
                        break;
                    case 3:
                        Console.Write("Введите имя:");
                        name = Console.ReadLine();
                        Console.Write("Введите вес:");
                        weight = ReadDoubleDigit();
                        animal = new Mammal(name, weight);
                        Console.WriteLine("Объект создан");
                        return animal;
                        break;
                    case 4:
                        Console.Write("Введите имя:");
                        name = Console.ReadLine();
                        Console.Write("Введите вес:");
                        weight = ReadDoubleDigit();
                        Console.Write("Введите длину шерсти:");
                        wingSize = ReadDoubleDigit();
                        animal = new Mammal(name, weight, wingSize);
                        return animal;
                        Console.WriteLine("Объект создан");
                        break;
                    case 0:
                        return null;
                        break;
                    default:
                        Console.WriteLine("Ошибка ввода операции, выберите операцию из списка");
                        return null;
                        break;


                }
                if (op == 0)
                    break;
            } while (true);
        }
        static Artiodactyl ArtioChoose()
        {
            int op;
            do
            {
                op = GetCreationArtioStart();
                Artiodactyl animal;
                string name;
                double weight;
                double wingSize;
                double hoofSize;
                switch (op)
                {
                    case 1:
                        animal = new Artiodactyl();
                        Console.WriteLine("Объект создан");
                        return animal;
                        break;
                    case 2:
                        Console.Write("Введите имя:");
                        name = Console.ReadLine();
                        animal = new Artiodactyl(name);
                        Console.WriteLine("Объект создан");
                        return animal;
                        break;
                    case 3:
                        Console.Write("Введите имя:");
                        name = Console.ReadLine();
                        Console.Write("Введите вес:");
                        weight = ReadDoubleDigit();
                        animal = new Artiodactyl(name, weight);
                        Console.WriteLine("Объект создан");
                        return animal;
                        break;
                    case 4:
                        Console.Write("Введите имя:");
                        name = Console.ReadLine();
                        Console.Write("Введите вес:");
                        weight = ReadDoubleDigit();
                        Console.Write("Введите длину шерсти:");
                        wingSize = ReadDoubleDigit();
                        animal = new Artiodactyl(name, weight, wingSize);
                        Console.WriteLine("Объект создан");
                        return animal;
                        break;
                    case 5:
                        Console.Write("Введите имя:");
                        name = Console.ReadLine();
                        Console.Write("Введите вес:");
                        weight = ReadDoubleDigit();
                        Console.Write("Введите длину шерсти:");
                        wingSize = ReadDoubleDigit();
                        Console.Write("Введите размер копыта:");
                        hoofSize = ReadDoubleDigit();
                        animal = new Artiodactyl(name, weight, wingSize, hoofSize);
                        Console.WriteLine("Объект создан");
                        return animal;
                        break;
                    case 0:
                        return null;
                        break;
                    default:
                        Console.WriteLine("Ошибка ввода операции, выберите операцию из списка");
                        return null;
                        break;
                }
                if (op == 0)
                    break;
            } while (true);
        }
        static int ReadIntDigit()
        {
            int digit;
            bool isConvert;
            string buf;
            do
            {
                buf = Console.ReadLine();
                isConvert = int.TryParse(buf, out digit);
                if (!isConvert)
                {
                    Console.WriteLine("Ошибка ввода, введите целое число:");
                }
            }
            while (!isConvert);
            return digit;
        }
        static double ReadDoubleDigit()
        {
            double digit;
            bool isConvert;
            string buf;
            do
            {
                buf = Console.ReadLine();
                isConvert = double.TryParse(buf, out digit);
                if (!isConvert)
                {
                    Console.WriteLine("Ошибка ввода, введите целое число:");
                }
            }
            while (!isConvert);
            return digit;
        }
        static int GetOperationStart()
        {
            int operation;
            Console.Write("\nВыберите операцию:\n" +
                 "1) создать объект класса Animal;\n" +
                 "2) создать объект класса Bird;\n" +
                 "3) создать объект класса Mammal;\n" +
                 "4) создать объект класса Artiodactyl;\n" +
                 "5) вывести массив;\n" +
                 "6) кол-во птиц в зоопарке;\n" +
                 "7) средний вес зверей в зоопарке;\n" +
                 "8) список имен всех зверей;\n" +
                 "9) cортировка по весу;\n" +
                 "10) сортировка по именам;\n" +
                 "11) добавление случаных объектов;\n" +
                 "12) очистить массив;\n" +
                 "13) клонирование и копирование;\n" +
                 "0) выход;\n" +
                 "Выбранная операция: "); ;
            operation = ReadIntDigit();
            return operation;
        }
        static int GetCopyStart()
        {
            int operation;
            Console.Write("\nВыберите операцию:\n" +
                 "1) копия и клон класса Animal;\n" +
                 "2) копия и клон класса Bird;\n" +
                 "3) копия и клон класса Mammal;\n" +
                 "4) копия и клон класса Artiodactyl;\n" +
                 "0) выход;\n" +
                 "Выбранная операция: "); ;
            operation = ReadIntDigit();
            return operation;
        }
        static int GetCreationStart()
        {
            int operation;
            Console.Write("\nВыберите операцию:\n" +
                 "1) создать объект по умолчанию;\n" +
                 "2) создать объект с заданным именем;\n" +
                 "3) создать объект с заданным именем и весом;\n" +
                 "0) выход;\n" +
                 "Выбранная операция: "); ;
            operation = ReadIntDigit();
            return operation;
        }
        static int GetCreationBirdStart()
        {
            int operation;
            Console.Write("\nВыберите операцию:\n" +
                 "1) создать объект по умолчанию;\n" +
                 "2) создать объект с заданным именем;\n" +
                 "3) создать объект с заданным именем и весом;\n" +
                 "4) создать объект с заданным именем, весом, размахом крыльев;\n" +
                 "0) выход;\n" +
                 "Выбранная операция: "); ;
            operation = ReadIntDigit();
            return operation;
        }
        static int GetCreationMammalStart()
        {
            int operation;
            Console.Write("\nВыберите операцию:\n" +
                 "1) создать объект по умолчанию;\n" +
                 "2) создать объект с заданным именем;\n" +
                 "3) создать объект с заданным именем и весом;\n" +
                 "4) создать объект с заданным именем, весом, длиной шерсти;\n" +
                 "0) выход;\n" +
                 "Выбранная операция: "); ;
            operation = ReadIntDigit();
            return operation;
        }
        static int GetCreationArtioStart()
        {
            int operation;
            Console.Write("\nВыберите операцию:\n" +
                 "1) создать объект по умолчанию;\n" +
                 "2) создать объект с заданным именем;\n" +
                 "3) создать объект с заданным именем и весом;\n" +
                 "4) создать объект с заданным именем, весом, длиной шерсти;\n" +
                 "5) создать объект с заданным именем, весом, длиной шерсти, размером копыта;\n" +
                 "0) выход;\n" +
                 "Выбранная операция: "); ;
            operation = ReadIntDigit();
            return operation;
        }
        static int GetCloneStart()
        {
            int operation;
            Console.Write("\nВыберите операцию:\n" +
                 "1) копировать и клонировать объект класса Animal;\n" +
                 "2) копировать и клонировать объект класса Bird;\n" +
                 "3) копировать и клонировать объект класса Mammal;\n" +
                 "4) копировать и клонировать объект класса Artiodactyl;\n" +
                 "0) выход;\n" +
                 "Выбранная операция: "); ;
            operation = ReadIntDigit();
            return operation;
        }
        static bool IsEmptyArr(Animal[] arr)
        {
            if (arr.Length == 0)
            {
                Console.WriteLine("Массив пуст");
                return true;
            }
            return false;
        }
        static void AddToArray(ref Animal[] array, Animal item)
        {
            Array.Resize(ref array, array.Length + 1);
            array[array.Length - 1] = item;
        }
        static void AddToArray(ref string[] array, string item)
        {
            Array.Resize(ref array, array.Length + 1);
            array[array.Length - 1] = item;
        }
        static int BirdsAmount()
        {
            int amount = 0; 
            foreach (Animal beast in zoo)
            {
                if (beast is Bird)
                {
                    amount++;
                }
            }
            return amount;
        }
        static double AverageWeight()
        {   
            if (!IsEmptyArr(zoo))
            {
                int amount = 0;
                double all = 0;
                foreach (Animal beast in zoo)
                {
                    amount++;
                    all += beast.Weight;
                }

                double medium = all / amount;
                return medium;
            }
            return 0;
        }
        static void GetNames()
        {
            if (!IsEmptyArr(zoo))
            {
                foreach (Animal beast in zoo)
                {
                    Console.Write(beast.Name + " ");
                }
            }
        }
        static void PrintArray(Animal []zoo)
        {
            foreach (Animal beast in zoo)
            {
                beast.Print();
            }
        }
        static void RandomArray(ref Animal []zoo, int size) {
            for (int i = 0; i<size; ++i)
            {
                Random rnd = new Random();
                int creation = rnd.Next(0, 4);
                if (creation == 0)
                {
                    Animal animal = new Animal();
                    animal.RandomInit();
                    AddToArray(ref zoo, animal);
                }
                if (creation == 1)
                {
                    Bird animal = new Bird();
                    animal.RandomInit();
                    AddToArray(ref zoo, animal);
                }
                if (creation == 2)
                {
                    Mammal animal = new Mammal();
                    animal.RandomInit();
                    AddToArray(ref zoo, animal);
                }
                if (creation == 3)
                {
                    Artiodactyl animal = new Artiodactyl();
                    animal.RandomInit();
                    AddToArray(ref zoo,animal);
                }
                
            }
        }
        static void Main(string[] args)
        {
            
            
            Task();
            //Animal animal = new Animal();
            ////animal.Print();

            //Bird bird = new Bird("Jimmy", 4, 55);
            //Bird birdes = new Bird("Hoollo", 8, 11);
            ////bird.Print();

            //Mammal bear = new Mammal("bear", 300, 10);
            ////bear.Print();

            //Artiodactyl pig = new Artiodactyl("piggo", 20, 0.4, 10);
            ////pig.Print();
            //// 1 part
            //// 2 part Средний вес животных заданного вида в зоопарке, Наименование птиц в зоопарке, 

            //Animal[] zoo = { animal, bird, bear, pig, birdes};
            //int amount = 0;
            //double all = 0;
            //foreach(Animal beast in zoo)
            //{
            //    beast.Print();
            //    if (beast is Bird) {
            //        amount++;
            //        all += beast.Weight;
            //    }
            //}
            //foreach (Animal beast in zoo)
            //{
              
            //    if (beast is Bird)
            //    {
            //        Console.Write(beast.Name + " ");
            //    }
            //}
           
            //double medium = all / amount;
            //Console.WriteLine($"Средний вес птиц в зоопарке {medium}");
            //// 3 part  IComparable
            //Console.WriteLine();
            //Console.WriteLine();
            //Array.Sort(zoo);
            //foreach (Animal beast in zoo)
            //{
            //    beast.Print();
            //    if (beast is Bird)
            //    {
            //        amount++;
            //        all += beast.Weight;
            //    }
            //}
            //Console.WriteLine();
            //Console.WriteLine();
            //// 3 part  ICompare
            //Array.Sort(zoo, new AnimalComparer());
            //foreach (Animal beast in zoo)
            //{
            //    beast.Print();
            //}
            //Console.WriteLine();
            //Animal p1 = new Animal("", 2);
            //p1.Print();
            //Console.WriteLine();
            //p1 = animal;
            //p1.Print();
            //Console.WriteLine();
            //p1 = animal.ShallowCopy();
            //p1.Print();
            //Console.WriteLine();
            //p1 = (Animal)p1.Clone();
            //p1.Print();
            //Console.WriteLine();
            //Artiodactyl p2 = new Artiodactyl();
            //p2 = (Artiodactyl)pig.Clone();
            //p2.Print();
            //Console.WriteLine();
            //Artiodactyl test = new Artiodactyl();
            //test.Print();
            //test.RandomInit();
            //test.Print();
        }
    }
}
