#include<bits/stdc++.h>
using namespace std;
int order, d[100];
bool through[100];

int passing_nearest(int indexor) {
	int temp = INT_MAX, nindexer = -1;
	for (int j = 0; j < order; j++) {
		if (j != indexor) {
			int temp_ = abs(d[j] - d[indexor]);
			if (temp_ < temp || (temp_ == temp && j < nindexer)) {
				nindexer = j;
				temp = temp_;
				through[j] = true;
			}
		}
	}
	return nindexer;
}

void self_passing(int init) {
	for (int j = 0; j < order; j++) {
		through[j] = false;
	}
	int media = passing_nearest(init), counter = 1;
	while (media != init) {
		media = passing_nearest(media);
	}
}

int main() {
	int ncounter = INT_MAX, final_index;
	cin >> order;
	for (int i = 0; i < order; i++) {
		cin >> d[i];
	}
	sort(d, d + order);
	if (order >= 0 && order <= 2) {
		cout << order;
		return 0;
	}

	for (int i = 0; i < order; i++) {
		self_passing(i);
		if (!through[i])++final_index;
	}
	std::cout << final_index;
	return 0;
}
