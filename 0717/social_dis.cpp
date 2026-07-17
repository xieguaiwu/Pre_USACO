#include<bits/stdc++.h>
#include <cstddef>
#include <iterator>
#include <vector>
using namespace std;

int main() {
	int stalls, dis;
	string s;
	cin >> s;

	vector<int> pos(stalls, 0);
	for (int i = 0; i < stalls; ++i) {
		if (s[i] == '1') pos.push_back(i);
	}

	int current_min = stalls + 1;
	for (size_t i = 0; i < pos.size() - 1; ++i) {
		current_min = min(current_min, pos[i + 1] - pos[i]);
	}

	//计算各个空隙提供的间距
	int l1 = pos[0];
	int r1 = stalls - 1 - pos.back(); //IMP
	int max_gap = 0;
	for (size_t i = 0; i < pos.size() - 1; ++i) {
		//放中间的间距是远距离的一半向下取整
		int gap = (pos[i + 1] - pos[i]) / 2;
		max_gap = max(gap, max_gap);
	}

	cout << max({l1, r1, max_gap}) << "\n";

	
}
