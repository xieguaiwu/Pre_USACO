#include <iostream>

using namespace std;

int main() {
	int matrix[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	int *ptr = &matrix[0][0];
	for (int i = 0; i < 9; ++i) {
		cout << *(ptr + i) << " ";
		if ((i + 1) % 3 == 0) cout << "\n";
	}
}
