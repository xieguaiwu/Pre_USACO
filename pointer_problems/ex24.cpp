#include <iostream>

using namespace std;

int main() {
	float *ptr = new float;
	*ptr = 3.14;
	cout << "Dynamically allocated float value: " << *ptr << "\nAddress on heap: " << ptr << "\n";
	delete ptr;
}
