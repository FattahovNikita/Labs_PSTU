#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int x, y, k;
	srand(time(NULL));
	x = rand() % 100 + 1;
	k = 7;
	cout << "Загадано число от 1 до 100, у вас есть "<< k << " попыток чтобы отгадать его" << endl;
	cout << "Введите число которое больше или равно загаданного" << endl;
	for (int i = 1; i <= k; ++i) {
		cin >> y;
		if (x == y) {
			cout << "Это загадонное число,вы победили" << endl;
		}
		if (y > x) {
			cout << "Ваше число больше загаданного" << endl;
			cout << "Осталось попыток:" << k-i << endl;
		}
		if (x > y) {
			cout << "Ваше число меньше загаданного" << endl;
			cout << "Осталось попыток:" << k-i << endl;
		}
	}
	cout << "Попытки кончились, вы проиграли" << endl;
	return 0;
}