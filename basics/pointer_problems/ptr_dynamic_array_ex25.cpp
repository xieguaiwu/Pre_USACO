#include <iostream>

using namespace std;

int main() {
	int *ptr = new int[8]();
	cout << "Dynamically allocated array: ";
	for (int i = 0; i < 8; ++i) {
		cout << (*(ptr + i) + 1 + i) * 10 << " ";
	}

	delete[] ptr;
}
