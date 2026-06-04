#include <iostream>

using namespace std;

int main() {
	int x = 5;
	//int y = 25;
	int* const const_ptr = &x; //the pointer must always point to the same memory location, but the value at that location can be changed
	*const_ptr = 10;
	cout << "x after modification via pointer: " << x << "\n";
}
