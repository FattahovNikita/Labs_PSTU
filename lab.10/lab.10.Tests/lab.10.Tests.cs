using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using AnimalLibrary;
using lab._10;

namespace lab._10.Tests
{
    [TestClass]
    public class AnimalTests
    {
        [TestMethod()]
        public void EmptyConstructor_ClassInstanceCreation_CorrectResult()
        {

            string expectedName = "безымяный";
            int expectedWeight = 1;

            Animal obj = new Animal();

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
        }

        [TestMethod()]
        public void ParameterizedConstructor1_ClassInstanceCreation_CorrectResult()
        {
            string expectedName = "Nick";
            int expectedWeight = 1;
            Animal obj = new Animal(expectedName);

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
        }

        [TestMethod()]
        public void ParameterizedConstructor2_ClassInstanceCreation_CorrectResult()
        {
            string expectedName = "Nick";
            int expectedWeight = 5;
            Animal obj = new Animal(expectedName, expectedWeight);

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
        }
        [TestMethod()]
        public void CompareTo_Сomparisons_CorrectResult()
        {
            int expectedPersonCompareToPersonResult = 1;

            Animal firstPerson = new Animal("Goga", 20);
            Animal secondPerson = new Animal("Vladimir", 10);

            Assert.AreEqual(expectedPersonCompareToPersonResult, firstPerson.CompareTo(secondPerson));
        }

        [TestMethod()]
        public void ShallowCopy_FunctionCall_CorrectResult()
        {
            Animal obj = new Animal();
            Animal newObj = obj.ShallowCopy();

            Assert.IsInstanceOfType(obj, typeof(Animal));
            Assert.AreNotSame(newObj, obj);
        }
        [TestMethod()]
        public void Clone_FunctionCall_CorrectResult()
        {
            Animal obj = new Animal();
            Animal newObj = (Animal)obj.Clone();

            Assert.IsInstanceOfType(obj, typeof(Animal));
            Assert.AreNotSame(newObj, obj);
        }
        [TestMethod()]
        public void RandomInit_FunctionCall_CorrectResult()
        {
            string[] exceptedNames = { "James", "Maria", "Kate", "Nick", "John", "Sofy", "Rufy", "Max", "Niko" };
            int expectedIntervalLeftBoundary = 1;
            int expectedIntervalRightBoundary = 100;

            Animal obj = new Animal();
            obj.RandomInit();
            for (int i = 0; i < exceptedNames.Length; ++i)
            {
                if (obj.Name == exceptedNames[i])
                {
                    Assert.IsTrue(obj.Name == exceptedNames[i]);
                    break;
                }
                if (i == exceptedNames.Length - 1)
                    Assert.IsTrue(obj.Name == exceptedNames[i]);
            }
            Assert.IsTrue(expectedIntervalLeftBoundary <= obj.Weight
                          && obj.Weight <= expectedIntervalRightBoundary);
        }
    }

    [TestClass]
    public class BirdTests
    {
        [TestMethod()]
        public void EmptyConstructor_ClassInstanceCreation_CorrectResult()
        {

            string expectedName = "безымяный";
            int expectedWeight = 1;

            Bird obj = new Bird();

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
        }

        [TestMethod()]
        public void ParameterizedConstructor1_ClassInstanceCreation_CorrectResult()
        {
            string expectedName = "Nick";
            int expectedWeight = 1;
            Bird obj = new Bird(expectedName);

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
        }

        [TestMethod()]
        public void ParameterizedConstructor2_ClassInstanceCreation_CorrectResult()
        {
            string expectedName = "Nick";
            int expectedWeight = 5;
            Bird obj = new Bird(expectedName, expectedWeight);

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
        }
        [TestMethod()]
        public void ParameterizedConstructor3_ClassInstanceCreation_CorrectResult()
        {
            string expectedName = "Nick";
            int expectedWeight = 5;
            int expectedWingSize = 5;
            Bird obj = new Bird(expectedName, expectedWeight, expectedWingSize);

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
            Assert.AreEqual(expectedWingSize, obj.WingSize);
        }
        [TestMethod()]
        public void CompareTo_Сomparisons_CorrectResult()
        {
            int expectedPersonCompareToPersonResult = 1;

            Bird firstPerson = new Bird("Goga", 20);
            Bird secondPerson = new Bird("Vladimir", 10);

            Assert.AreEqual(expectedPersonCompareToPersonResult, firstPerson.CompareTo(secondPerson));
        }

        [TestMethod()]
        public void ShallowCopy_FunctionCall_CorrectResult()
        {
            Bird obj = new Bird();
            Bird newObj = obj.ShallowCopy();

            Assert.IsInstanceOfType(obj, typeof(Bird));
            Assert.AreNotSame(newObj, obj);
        }
        [TestMethod()]
        public void Clone_FunctionCall_CorrectResult()
        {
            Bird obj = new Bird();
            Bird newObj = (Bird)obj.Clone();

            Assert.IsInstanceOfType(obj, typeof(Bird));
            Assert.AreNotSame(newObj, obj);
        }
        [TestMethod()]
        public void RandomInit_FunctionCall_CorrectResult()
        {
            string[] exceptedNames = { "James", "Maria", "Kate", "Nick", "John", "Sofy", "Rufy", "Max", "Niko" };

            int expectedIntervalLeftBoundary = 1;
            int expectedIntervalRightBoundary = 50;
            int expectedWingIntervalLeftBoundary = 1;
            int expectedWingIntervalRightBoundary = 100;

            Bird obj = new Bird();
            obj.RandomInit();
            for (int i = 0; i < exceptedNames.Length; ++i)
            {
                if (obj.Name == exceptedNames[i])
                {
                    Assert.IsTrue(obj.Name == exceptedNames[i]);
                    break;
                }
                if (i == exceptedNames.Length - 1)
                    Assert.IsTrue(obj.Name == exceptedNames[i]);
            }
            Assert.IsTrue(expectedIntervalLeftBoundary <= obj.Weight
                          && obj.Weight <= expectedIntervalRightBoundary);
            Assert.IsTrue(expectedWingIntervalLeftBoundary <= obj.WingSize
                          && obj.WingSize <= expectedWingIntervalRightBoundary);
        }
    }

    [TestClass]
    public class MammalTests
    {
        [TestMethod()]
        public void EmptyConstructor_ClassInstanceCreation_CorrectResult()
        {

            string expectedName = "безымяный";
            int expectedWeight = 1;

            Mammal obj = new Mammal();

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
        }

        [TestMethod()]
        public void ParameterizedConstructor1_ClassInstanceCreation_CorrectResult()
        {
            string expectedName = "Nick";
            int expectedWeight = 1;
            Mammal obj = new Mammal(expectedName);

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
        }

        [TestMethod()]
        public void ParameterizedConstructor2_ClassInstanceCreation_CorrectResult()
        {
            string expectedName = "Nick";
            int expectedWeight = 5;
            Mammal obj = new Mammal(expectedName, expectedWeight);

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
        }
        [TestMethod()]
        public void ParameterizedConstructor3_ClassInstanceCreation_CorrectResult()
        {
            string expectedName = "Nick";
            int expectedWeight = 5;
            int expectedHairLength = 5;
            Mammal obj = new Mammal(expectedName, expectedWeight, expectedHairLength);

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
            Assert.AreEqual(expectedHairLength, obj.HairLength);
        }
        [TestMethod()]
        public void CompareTo_Сomparisons_CorrectResult()
        {
            int expectedPersonCompareToPersonResult = 1;

            Mammal firstPerson = new Mammal("Goga", 20);
            Mammal secondPerson = new Mammal("Vladimir", 10);

            Assert.AreEqual(expectedPersonCompareToPersonResult, firstPerson.CompareTo(secondPerson));
        }

        [TestMethod()]
        public void ShallowCopy_FunctionCall_CorrectResult()
        {
            Mammal obj = new Mammal();
            Mammal newObj = obj.ShallowCopy();

            Assert.IsInstanceOfType(obj, typeof(Mammal));
            Assert.AreNotSame(newObj, obj);
        }
        [TestMethod()]
        public void Clone_FunctionCall_CorrectResult()
        {
            Mammal obj = new Mammal();
            Mammal newObj = (Mammal)obj.Clone();

            Assert.IsInstanceOfType(obj, typeof(Mammal));
            Assert.AreNotSame(newObj, obj);
        }
        [TestMethod()]
        public void RandomInit_FunctionCall_CorrectResult()
        {
            string[] exceptedNames = { "James", "Maria", "Kate", "Nick", "John", "Sofy", "Rufy", "Max", "Niko" };

            int expectedIntervalLeftBoundary = 1;
            int expectedIntervalRightBoundary = 100;
            int expectedWingIntervalLeftBoundary = 1;
            int expectedWingIntervalRightBoundary = 50;

            Mammal obj = new Mammal();
            obj.RandomInit();

            for (int i = 0; i < exceptedNames.Length; ++i)
            {
                if (obj.Name == exceptedNames[i])
                {
                    Assert.IsTrue(obj.Name == exceptedNames[i]);
                    break;
                }
                if (i == exceptedNames.Length - 1)
                    Assert.IsTrue(obj.Name == exceptedNames[i]);
            }
            Assert.IsTrue(expectedWingIntervalLeftBoundary <= obj.Weight
                          && obj.Weight <= expectedWingIntervalRightBoundary);
            Assert.IsTrue(expectedIntervalLeftBoundary <= obj.HairLength
                          && obj.HairLength <= expectedIntervalRightBoundary);
        }
    }

    [TestClass]
    public class ArtiodactylTests
    {
        [TestMethod()]
        public void EmptyConstructor_ClassInstanceCreation_CorrectResult()
        {

            string expectedName = "безымяный";
            int expectedWeight = 1;

            Artiodactyl obj = new Artiodactyl();

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
        }

        [TestMethod()]
        public void ParameterizedConstructor1_ClassInstanceCreation_CorrectResult()
        {
            string expectedName = "Nick";
            int expectedWeight = 1;
            Artiodactyl obj = new Artiodactyl(expectedName);

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
        }

        [TestMethod()]
        public void ParameterizedConstructor2_ClassInstanceCreation_CorrectResult()
        {
            string expectedName = "Nick";
            int expectedWeight = 5;
            Artiodactyl obj = new Artiodactyl(expectedName, expectedWeight);

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
        }
        [TestMethod()]
        public void ParameterizedConstructor3_ClassInstanceCreation_CorrectResult()
        {
            string expectedName = "Nick";
            int expectedWeight = 5;
            int expectedHairLength = 5;
            Artiodactyl obj = new Artiodactyl(expectedName, expectedWeight, expectedHairLength);

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
            Assert.AreEqual(expectedHairLength, obj.HairLength);
        }
        [TestMethod()]
        public void ParameterizedConstructor4_ClassInstanceCreation_CorrectResult()
        {
            string expectedName = "Nick";
            int expectedWeight = 5;
            int expectedHairLength = 5;
            int expectedHoofSize = 5;
            Artiodactyl obj = new Artiodactyl(expectedName, expectedWeight, expectedHairLength, expectedHoofSize);

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedWeight, obj.Weight);
            Assert.AreEqual(expectedHairLength, obj.HairLength);
            Assert.AreEqual(expectedHoofSize, obj.HoofSize);
        }
        [TestMethod()]
        public void CompareTo_Сomparisons_CorrectResult()
        {
            int expectedPersonCompareToPersonResult = 1;

            Artiodactyl firstPerson = new Artiodactyl("Goga", 20);
            Artiodactyl secondPerson = new Artiodactyl("Vladimir", 10);

            Assert.AreEqual(expectedPersonCompareToPersonResult, firstPerson.CompareTo(secondPerson));
        }

        [TestMethod()]
        public void ShallowCopy_FunctionCall_CorrectResult()
        {
            Artiodactyl obj = new Artiodactyl();
            Artiodactyl newObj = obj.ShallowCopy();

            Assert.IsInstanceOfType(obj, typeof(Artiodactyl));
            Assert.AreNotSame(newObj, obj);
        }
        [TestMethod()]
        public void Clone_FunctionCall_CorrectResult()
        {
            Artiodactyl obj = new Artiodactyl();
            Artiodactyl newObj = (Artiodactyl)obj.Clone();

            Assert.IsInstanceOfType(obj, typeof(Artiodactyl));
            Assert.AreNotSame(newObj, obj);
        }
        [TestMethod()]
        public void RandomInit_FunctionCall_CorrectResult()
        {
            string[] exceptedNames = { "James", "Maria", "Kate", "Nick", "John", "Sofy", "Rufy", "Max", "Niko" };

            int expectedIntervalLeftBoundary = 1;
            int expectedIntervalRightBoundary = 100;
            int expectedWingIntervalLeftBoundary = 1;
            int expectedWingIntervalRightBoundary = 50;

            Artiodactyl obj = new Artiodactyl();
            obj.RandomInit();

            for (int i = 0; i < exceptedNames.Length; ++i)
            {
                if (obj.Name == exceptedNames[i])
                {
                    Assert.IsTrue(obj.Name == exceptedNames[i]);
                    break;
                }
                if (i == exceptedNames.Length - 1)
                    Assert.IsTrue(obj.Name == exceptedNames[i]);
            }
            Assert.IsTrue(expectedIntervalLeftBoundary <= obj.Weight
                          && obj.Weight <= expectedIntervalRightBoundary);
            Assert.IsTrue(expectedIntervalLeftBoundary <= obj.HairLength
                          && obj.HairLength <= expectedIntervalRightBoundary);
            Assert.IsTrue(expectedWingIntervalLeftBoundary <= obj.HoofSize
                          && obj.HoofSize <= expectedWingIntervalRightBoundary);

        }
    }
    [TestClass]
    public class PersonTests
    {
        [TestMethod()]
        public void EmptyConstructor_ClassInstanceCreation_CorrectResult()
        {

            string expectedName = "безымяный";
            int expectedAge = 25;

            Person obj = new Person();

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedAge, obj.Age);
        }

        [TestMethod()]
        public void ParameterizedConstructor1_ClassInstanceCreation_CorrectResult()
        {
            string expectedName = "Nick";
            int expectedAge = 25;

            Person obj = new Person(expectedName);

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedAge, obj.Age);
        }

        [TestMethod()]
        public void ParameterizedConstructor2_ClassInstanceCreation_CorrectResult()
        {
            string expectedName = "Nick";
            int expectedAge = 40;

            Person obj = new Person(expectedName, expectedAge);

            Assert.AreEqual(expectedName, obj.Name);
            Assert.AreEqual(expectedAge, obj.Age);
        }
        public void RandomInit_FunctionCall_CorrectResult()
        {
            string[] exceptedNames = { "James", "Maria", "Kate", "Nick", "John", "Sofy", "Rufy", "Max", "Niko" };
            int expectedIntervalLeftBoundary = 1;
            int expectedIntervalRightBoundary = 100;

            Person obj = new Person();
            obj.RandomInit();
            for (int i = 0; i < exceptedNames.Length; ++i)
            {
                if (obj.Name == exceptedNames[i])
                {
                    Assert.IsTrue(obj.Name == exceptedNames[i]);
                    break;
                }
                if (i == exceptedNames.Length - 1)
                    Assert.IsTrue(obj.Name == exceptedNames[i]);
            }
            Assert.IsTrue(expectedIntervalLeftBoundary <= obj.Age
                          && obj.Age <= expectedIntervalRightBoundary);
        }
    }
}

