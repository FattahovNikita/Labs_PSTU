#include <iostream>
using namespace std;
int main(){
	setlocale(LC_ALL, "Russian");
	char a, b, c, d, e;
	cout << "Введите 5 символов " << endl;
	cin >> a >> b >> c >> d >> e;
	cout <<"Символы в обратном порядке - "<< e << d << c << b << a << endl;
	return 0;
}