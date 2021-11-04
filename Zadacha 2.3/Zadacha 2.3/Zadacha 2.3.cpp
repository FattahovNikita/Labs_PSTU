#include <iostream>
using namespace std;
int main() {
	const int z = 10;
	int x;
	x = 20;
	cout << z << endl;   // выводим целочисленную константу
	cout << x << endl;   // выводим целочисленную переменную
	cout << --x << endl; // выводим переменную через декремент
	return 0;
}