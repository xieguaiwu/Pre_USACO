#include <iostream>

using  namespace std;

int main() {
	int number = 50;
	int *num_ptr = &number;
	*num_ptr = 99;
	cout << "The final value of number is: " << number << "\n";
}
