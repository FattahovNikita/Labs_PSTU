#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int x,a,b,c;
	bool F = 0;
	cout << "Введите трехзначное число у которого все цифры отличаются друг от друга:";
	cin >> x;
	while ((x < 100) || (x > 999)) {
		cout << "Некорректный ввод, введите трехзначное число:";
		cin >> x;
	}
		a = x % 10;
		x /= 10;
		b = x % 10;
		c = x / 10;
	while (F == 0) {
		if ((a == b) || (a == c) || (b == c)) {
			cout << "Некорректный ввод, введите трехзначное число:";
			cin >> x;
			while ((x < 100) || (x > 999)) {
				cout << "Некорректный ввод, введите трехзначное число:";
				cin >> x;
			}
			a = x % 10;
			x /= 10;
			b = x % 10;
			c = x / 10;
		}
		else F = 1;

	}
	cout << "Комбинации:" << endl;
	cout << a << b << c << endl;
	cout << a << c << b << endl;
	cout << b << a << c << endl;
	cout << b << c << a << endl;
	cout << c << a << b << endl;
	cout << c << b << a << endl;
	if ((a > b) & (a > c) & (b > c))
		cout << "Самое большое число:" << a << b << c << endl;
	if ((a > b) & (a > c) & (c > b))
		cout << "Самое большое число:" << a << c << b << endl;
	if ((b > a) & (b > c) & (a > c))
		cout << "Самое большое число:" << b << a << c << endl;
	if ((b > a) & (b > c) & (c > a))
		cout << "Самое большое число:" << b << c << a << endl;
	if ((c > a) & (c > b) & (a > b))
		cout << "Самое большое число:" << c << a << b << endl;
	if ((c > a) & (c > b) & (b > a))
		cout << "Самое большое число:" << c << b << a << endl;

	return 0;
}	

