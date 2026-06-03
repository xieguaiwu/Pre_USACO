#include <iostream>
#include <limits>

using namespace std;

int main() {
	int *safe_ptr = nullptr;
	if (safe_ptr == nullptr) {
		cout << "Pointer is null, cannot dereference.\n";
	}
	int newone = 77;
	safe_ptr = &newone;
	if (safe_ptr != nullptr) {
		cout << "Pointer is now valid. Dereferenced value: " << *safe_ptr << "\n";
	}
}
