#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	float g;
	cout << "Введите число галлонов" << endl;
	cin >> g;														// вводим кол-во галлонов
	cout << g / 7.481 << " - Эквивалентный объем в футах" << endl;	// выводим кол-во футов через формулу
	return 0;
}