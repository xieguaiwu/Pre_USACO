#include <iostream>

using namespace std;

void print_constant_value(const int* shit) {
	cout << "Value via const pointer: " << *shit << "\n";
}

int main() {
	int data = 100;
    print_constant_value(&data);
    data = 200;
    print_constant_value(&data);
}
