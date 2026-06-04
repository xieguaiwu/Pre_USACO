#include <iostream>

using namespace std;

int main() {
	int data[] = {10, 20, 30, 40, 50, 60};
	int start_index = 2;
	int end_index = 5;
	int *ptr = &data[0];
	cout << "Sub-array elements: ";
	for (int i = start_index; i < end_index; ++i) {
		cout << *(ptr + i) << " ";
	}
	cout << "\n";
}
