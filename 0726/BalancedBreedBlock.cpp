#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool judge(const vector<int> &v) {
	bool types[3];
	for (size_t i = 0; i < v.size(); ++i) {
		if (v[i] == 1) types[0] = true;
		if (v[i] == 2) types[1] = true;
		if (v[i] == 3) types[2] = true;
	}
	if (v[0] == true && v[1] == true && v[2] == true) return true;
	return false;
}

int main() {
	int N;
	cin >> N;
	vector <int> list(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> list[i];
	}
	//每种>=1牛，其最大breed count - min breed count <= 1
	int L, R, current = 0; //R-L<=1
	for (int i = 0; i < N - 1; ++i) {
		L = i;
		for (int j = 1; j < N; ++j) {
			R = j;
			vector <int> sublist;
			sublist.assign(list.begin() + L, list.begin() + R);
			if (list[R] - list[L] <= 1 && judge(sublist)) {
				current = max(R - L, current);
			}
		}
	}
	cout << current << "\n";
}
