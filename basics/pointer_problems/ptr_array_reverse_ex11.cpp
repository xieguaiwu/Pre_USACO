#include <iostream>

using namespace std;

int main() {
	int numbers[] = {1, 2, 3, 4, 5};
	int *ptr = &numbers[4];
	cout << "Elements in reverse order: ";
	for (int i = 0; i < (int)(sizeof(numbers) / sizeof(numbers[4])); ++i) {
		cout << *(ptr - i) << " ";
	}
	cout << "\n";
}
