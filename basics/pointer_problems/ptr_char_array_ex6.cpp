#include <iostream>

using namespace std;

int main() {
	char word[] = "CODE";
	char *p = &word[0];
	cout << "The third character is: " << *(p + 2) << "\n";
}
