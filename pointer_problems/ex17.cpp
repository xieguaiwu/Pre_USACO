#include <iostream>
#include <utility>

using namespace std;

void swap(int *r1, int *r2) {
	int ptr = *r1;
	*r1 = *r2;
	*r2 = ptr;
}

int main() {
	int a = 10;
	int b = 20;
	cout << "Before swap: a = " << a << ",b = " << b << "\n";
	swap(&a, &b);
	cout << "After swap: a = " << a << ",b = " << b << "\n";
}
