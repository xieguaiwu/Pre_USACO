#include <iostream>

using namespace std;

int main() {
	int n1 = 10;
	int n2 = 20;
	int n3 = 30;
	int n4 = 40;
	int n5 = 50;
	int *ptr[5];
	ptr[0] = &n1;
	ptr[1] = &n2;
	ptr[2] = &n3;
	ptr[3] = &n4;
	ptr[4] = &n5;
	cout << "Values via array of pointers: ";
	for (int i = 0; i < 5; ++i) {
		cout << *ptr[i] << " ";
	}
	cout << "\n";
}
