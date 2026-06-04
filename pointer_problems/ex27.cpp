#include <cstring>
#include <iostream>

using namespace std;

char *find_first_occurrence(char *text, char *target) {
	size_t text_len = strlen(text);
	size_t target_len = strlen(target);
	if (target_len == 0) return text;
	if (target_len > text_len) return nullptr;

	char first = target[0];
	for (size_t i = 0; i <= text_len - target_len; ++i) {
		if (text[i] == first) {
			size_t j = 0;
			while (j < target_len && text[i + j] == target[j]) {
				++j;
			}
			if (j == target_len) return text + i;
		}
	}
	return nullptr;
}

int main() {
	char main_str[] = "programming in c++ is fun";
	char sub_str[] = "c++";
	char *ass = find_first_occurrence(main_str, sub_str);
	if (ass != nullptr) {
		cout << "Substring found starting at: " << ass << "\n";
		cout << "Source string starting from match: " << ass << "\n";
	} else {
		cout << "eat shit and die!\n";
	}
}
