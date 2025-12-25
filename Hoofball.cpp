#include<bits/stdc++.h>
using namespace std;

int order, d[100];//total and distance
bool through[100];//whether it is passed or not
int record_next[100], record_prev[100];

int passing_nearest(int indexor) {
	int temp = INT_MAX, nindexer = -1;//find nearest
	for (int j = 0; j < order; ++j) {
		if (j != indexor) {//only deal with non-passed
			int temp_ = abs(d[j] - d[indexor]);
			if (temp_ < temp || (temp_ == temp && j < nindexer)) {
				nindexer = j;
				temp = temp_;
			}
		}
	}
	return nindexer;
}

void self_passing(int init) {//mediate function
	while (!through[init]) {
		through[init] = true;
		init = record_next[init];
	}
}

int main() {
	int remain_counter = 0;
	cin >> order;
	for (int i = 0; i < order; ++i) {
		cin >> d[i];
	}
	sort(d, d + order);
	if (order >= 0 && order <= 2) {
		cout << order;
		return 0;
	}

	memset(record_prev, 0, sizeof(record_prev));
	memset(through, false, sizeof(through));

	for (int i = 0; i < order; ++i) {
		record_next[i] = passing_nearest(i);
		record_prev[record_next[i]]++;
	}

	//initialize
	for (int i = 0; i < order; ++i) {
		if (record_prev[i] == 0) {
			remain_counter++;
			self_passing(i); 
		}
	}
    
    //deal alone
	for (int i = 0; i < order; ++i) {
		if (!through[i]) {
			remain_counter++;
			self_passing(i);
		}
	}

	cout << remain_counter;
}
