#include <iostream>
#include <sched.h>

using namespace std;

int main() {
	int scores[] = {85, 90, 78, 95, 88};
	int *scores_ptr = &scores[0];
	cout << "The value of the third element is: " << *(scores_ptr + 2) << "\n";
}
