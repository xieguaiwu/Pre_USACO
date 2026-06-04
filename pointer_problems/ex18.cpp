#include <iostream>
#include <cctype>
using namespace std;

void to_uppercase(char *receive) {
    char *ptr = receive;
    while (*ptr != '\0') {
        *ptr = toupper(*ptr);
        ptr++;
    }
}

int main() {
	char text[] = "hello pointers exercise";
	cout << "Original: ";
	for (int i = 0; i < (int)sizeof(text); ++i) {
		cout << text[i];
	}
	cout << "\nAfter: ";
	to_uppercase(&text[0]);
	for (int i = 0; i < (int)sizeof(text); ++i) {
		cout << text[i];
	}
}
