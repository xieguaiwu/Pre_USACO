#include <iostream>

using namespace std;

struct Rectangle {
	int length;
	int width;
} shit;

int main() {
	shit = {10, 5};
	Rectangle *ptr = &shit;
	cout << "Original dimensions: " << ptr -> length << "*" << ptr -> width << "\n";
	ptr -> length = 15;
	ptr -> width = 7;
	cout << "Original dimensions: " << ptr -> length << "*" << ptr -> width << "\n";
}
