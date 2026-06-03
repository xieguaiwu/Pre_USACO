#include <iostream>

using namespace std;

int main() {
	int x = 42;
	int *p1 = &x;
	int **p2 = &p1;
	cout << "The value accessed via double pointer is: " << **p2 << "\n";
}
