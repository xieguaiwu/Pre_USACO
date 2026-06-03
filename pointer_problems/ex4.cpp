#include <iostream>

using namespace std;

int main() {
	int data[] = {10, 20, 30, 40, 50};
	int *data_ptr = &data[0];
	cout << "Elements using pointer increment: ";
	for (int i = 0; i < (int)(sizeof(data) / sizeof(data[0])); ++i) {
		cout << *(data_ptr + i) << " ";
	}
	cout << "\n";
}
