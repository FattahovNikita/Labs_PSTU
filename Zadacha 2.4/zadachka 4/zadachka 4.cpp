#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int f;
	cout << "Введите температуру в градусах Фаренгейта" << endl;
	cin >> f;
	cout << (f - 32) * 5 / 9 << " - Эквивалентная температура в градусах Цельсия" << endl;
	return 0;
}