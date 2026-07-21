#include<bits/stdc++.h>
using namespace std;

int frequency(const vector<int>& v) {
	int cnt = 0, candidate = 0;
	bool seen[101] = {false};
	for (int x : v) {
		if (!seen[x]) {
			seen[x] = true;
			cnt++;
			candidate = x;
		}
	}
	return cnt * 10 + candidate;
}

int main() {
	int N, K, max = 0;
	cin >> N >> K;
	vector<int> breed(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> breed[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int eat = i; eat < N; ++eat) {
			vector<int> sub(breed.begin() + i, breed.begin() + eat + 1);
			int result = frequency(sub);
			if (result / 10 <= K) {
				if (max < eat - i + 1) max = eat - i + 1;
			}
		}
	}
	cout << max;
}
