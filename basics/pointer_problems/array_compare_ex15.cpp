#include <iostream>

using namespace std;

template <size_t N>
bool compare_array(int (&num1)[N], int (&num2)[N]) {
	for (size_t i = 0; i < N; ++i) {
		if (num1[i] != num2[i]) return false;
	}
	return true;
}

int main() {
	int a1[] = {1, 2, 3, 4};
	int a2[] = {1, 2, 3, 4};
	int a3[] = {1, 2, 9, 4};
	cout << "Array a1 & a2 are ";
	if (!compare_array(a1, a2)) cout << "NOT";
	cout << "identical.\n";
	cout << "Array a1 & a3 are ";
	if (!compare_array(a1, a3)) cout << "NOT";
	cout << "identical.\n";
}
