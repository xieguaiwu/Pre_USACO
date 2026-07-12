#include <iostream>

using namespace std;

void resize_array(int *&ptr, int old_size, int new_size) {
	int *new_ptr = new int[new_size];
	for (int i = 0; i < old_size; ++i) {
		new_ptr[i] = ptr[i];
	}
	for (int i = old_size + 1; i < new_size; ++i) {
		new_ptr[i] = 99;
	}
	delete[] ptr;
	ptr = new_ptr;
}

void print_array(int arr[], size_t size) {
	for (size_t i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main() {
	const int old_size = 5;
	const int new_size = 10;
	int *ptr = new int[old_size] {1, 2, 3, 4, 5};

	cout << "Original array (size 5): ";
	print_array(ptr, old_size);

	resize_array(ptr, old_size, new_size);
	cout << "Resized array (size 10): ";
	print_array(ptr, new_size);
	delete[] ptr;
}
