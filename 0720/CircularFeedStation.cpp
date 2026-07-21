#include<bits/stdc++.h>

using namespace std;

int main() {
	int N, cost = 0;
	cin >> N;
	vector<int> cow(N + 1, 0);
	for (int i = 0; i < N; ++i) {
		cin >> cow[i];
	}

	long mincost = 1e10;
    int target = 0;
	for (int i = 0; i < N; ++i) {
		cost = 0;
		for (int j = 0; j < N; ++j) {
            int go = abs(i - j);
			cost += cow[j] * go;
		}
		if (mincost > cost)  {
			mincost = cost;
			target = i + 1;
		}
	}

	cout << target << " " << mincost << "\n";
}
