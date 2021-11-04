#include <iostream>
using namespace std;
int main() {
	int i = 1;                  // создаем переменную i = 1
	cout << ++i * i++ << endl;  // в начале i увеличивается на 1,потом i * i == 2 * 2, и в конце i увеличивается на 1
	return 0;
}
