#include<bits/stdc++.h>

using namespace std;

int highest(const vector<int>& v) {
	int x = v[0];
	for (size_t i = 1; i < v.size(); ++i) {
		x = max(x, v[i]);
	}
	return x;
}

int freq(const vector<int>& v, int p) {
	int f = 0;
	for (size_t i = 0; i < v.size(); ++i) {
		if (v[i] == p) ++f;
	}
	return f;
}

int circulate(const vector<int>& v) {
	return freq(v, highest(v));
}

vector<int> top_ids(const vector<int>& v) {
	int h = highest(v);
	vector<int> ids;
	for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == h) ids.push_back(i);
    }
	return ids;
}

int main() {
	int N, M, G, timer = 0;
	cin >> N >> M >> G;
	vector<int> cowlist(M, G);

	vector<array<int, 3 >> recs(N); //recs[0] = tag, [1] = newid, [2] = change 换存储方式来方便sort
	for (int i = 0; i < N; ++i) {
		cin >> recs[i][0] >> recs[i][1] >> recs[i][2];
	}
	sort(recs.begin(), recs.end());

	cowlist[recs[0][1] - 1] += recs[0][2];
	auto init = top_ids(cowlist);
	for (int i = 1; i < N; ++i) {
		cowlist[recs[i][1] - 1] += recs[i][2];
		auto cur = top_ids(cowlist);
		if (cur != init) {
			init = cur;
			++timer;
		}
	}
	cout << timer << "\n";
}
