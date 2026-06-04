#include <iostream>

using namespace std;

void copy_array(int target[], int source[], size_t the_size) {
	for (int i = 0; i < (int) the_size; ++i) {
		int *ptr = &source[0];
		target[i] = *(ptr + i);
	}
}

int main() {
	int source[] = {10, 20, 30, 40, 50};
	int shit[5];
	copy_array(shit, source, 5);
	cout << "Destination array contents: ";
	for (int i = 0; i < 5; ++i) {
		cout << shit[i] << " ";
	}
	cout << "\n";
}
