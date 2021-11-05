#include <iostream>
using namespace std;
int main() {
	int h1, m1, s1, h2, m2, s2, hf, mf, sf,t;
	setlocale(LC_ALL, "Russian");
	cout << "Введите начало временного отрезка в пределах одних суток" << endl;
	cout << "часы: ";
	cin >> h1;
	cout << "минуты: ";
	cin >> m1;
	cout << "секунды: ";
	cin >> s1;
	cout << "Введите конец временного отрезка в пределах одних суток" << endl;
	cout << "часы: ";
	cin >> h2;
	cout << "минуты: ";
	cin >> m2;
	cout << "секунды: ";
	cin >> s2;
	t = (h2 - h1) * 3600 + (m2 - m1) * 60 + s2 - s1;
	hf = t / 3600;
	mf = (t - hf * 3600) / 60;
	sf = t - hf * 3600 - mf * 60;
	cout << "Продолжительность промежутка составляет " << hf << " часов " << mf << " минут " << sf << " секунд ";
	return 0;
}