#include <iostream>

using namespace std;

int add(int x, int y) {
	return x + y;
}

int main() {
	int a = 10;
	int b = 5;
	int (*ptr)(int, int);
	ptr = add;
	int result = ptr(a, b);
	cout << "Result 1 (" << a << " + " << b << "): " << result << "\n";
}
