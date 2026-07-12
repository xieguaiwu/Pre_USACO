#include <iostream>

using namespace std;

int main() {
	int shit[5] = {1, 5, 10, 15, 20};
	int *ptr = &shit[0];
	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		sum += *(ptr + i);
	}
	cout << "The sum of the array is: " << sum << "\n";
}
