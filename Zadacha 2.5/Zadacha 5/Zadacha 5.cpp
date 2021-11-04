#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int x, y;
	cout << "Введите первое число" << endl;
	cin >> x;
	cout << "Введите второе число" << endl;
	cin >> y;
	cout << "Результат произведения чисел = " << x * y << endl;
	return 0;
}