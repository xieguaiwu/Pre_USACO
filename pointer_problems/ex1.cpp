#include<iostream>

using namespace std;

int main() {
	int value = 100;
	int *ptr = &value;
	cout << "The value is: " << *ptr << "\n";
}
