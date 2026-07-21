#include<bits/stdc++.h>

using namespace std;

int main() {
	int N, T, curW = 0;
	float mass = 0;
	cin >> N >> T;
	vector<pair<float, int >> ratio(N);
	for (int i = 0; i < N; ++i) {
		int w, v;
		cin >> w >> v;
		ratio[i] = {(float)v / w, w};
	}
	sort(ratio.begin(), ratio.end());

	int j = ratio.size() - 1;
	while (j >= 0 && curW < T) {
		int w = ratio[j].second;
		float r = ratio[j].first;
		if (curW + w <= T) {
			curW += w;
			mass += r * w;
		} else {
			mass += r * (T - curW);
			curW = T;
		}
		--j;
	}
	cout << fixed << setprecision(2) << mass << "\n";
}
