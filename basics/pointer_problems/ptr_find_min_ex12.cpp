#include <algorithm>
#include <cstddef>
#include <iterator>
#include <iostream>

using namespace std;

int *find_min_ptr(int shit[], size_t eat) {
	int *min = &shit[0];
	for (int i = 1; i < (int)eat; ++i) {
		if (*min > shit[i]) min = &shit[i];
	}
	return min;
}

int main() {
	int data[] = {45, 12, 67, 8, 33};
	cout << "The smallest element is: " << *find_min_ptr(data, std::size(data)) << "\n";
}
