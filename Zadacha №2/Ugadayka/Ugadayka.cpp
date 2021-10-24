#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int x,y,k;
	srand(time(NULL));
	x = rand() % 100 + 1;
	k = 1;
	cout << "Загаданно число от 1 до 100, у вас есть 7 попыток чтобы отгадать его" << endl;
	cout << "Введите число которое больше или равно загаданного" << endl;
	while (k < 8) {
		cin >> y;
		if (x == y) {
			cout << "Это загадонное число,вы победили" << endl;
		}
		if (y > x) {
			cout << "Ваше число больше загаданного" << endl;
			k += 1;
			cout << "Осталось попыток:"<< 8-k << endl;
		}
		if (x > y) {
			k += 1;
			cout << "Ваше число меньше загаданного" << endl;
			cout << "Осталось попыток:" << 8 - k << endl;
		}
	}
	cout << "Попытки кончились, вы проиграли" << endl;
}