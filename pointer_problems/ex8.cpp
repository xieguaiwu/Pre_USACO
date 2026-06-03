#include <iostream>

using namespace std;

void increment_value(int *ptr) {
	*ptr += 10;
}

int main() {
	int shit = 50;
	cout << "Before increment: " << shit << "\n";
	increment_value(&shit);
	cout << "After increment: " << shit << "\n";
}
