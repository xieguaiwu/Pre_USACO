#include<iostream>
#include<cstring>
using namespace  std;

string allname[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

int main() {
	string props;
	int realnames[8];
	unsigned char total_times, rn_index;
	cin >> total_times;

	for (unsigned char i = 0; i < total_times; ++i) {
		getline(cin, props);
		size_t spaces = props.find(" ");
		realnames[rn_index] = allname.indexOf(props.substr(0, spaces)));
		++rn_index;
	}

}
