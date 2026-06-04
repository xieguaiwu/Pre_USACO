#include <iostream>

using namespace std;

int multiply(int x1, int x2) {
	return x1 * x2;
}

int subtract(int x1, int x2) {
	return x1 - x2;
}

int compute_result(int y1, int y2, int (*ptr)(int, int)) {
	return ptr(y1, y2);
}

int main() {
	int x = 50;
	int y = 10;
	cout << "Multiplication result: " << compute_result(x, y, multiply) << "\n";
    cout << "Subtraction result: " << compute_result(x, y, subtract) << "\n";
}
