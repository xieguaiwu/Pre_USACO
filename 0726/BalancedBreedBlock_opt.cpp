#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> list(N);
	for (int i = 0; i < N; ++i) cin >> list[i];

	int ans = 0;
	for (int i = 0; i < N - 2; ++i) {
		int cnt[4] = {0};                       // cnt[1..3] 三种牛的计数
		for (int j = i; j < N; ++j) {
			cnt[list[j]]++;                     // ★ a[b[x]]: 用数组值做下标
			if (cnt[1] && cnt[2] && cnt[3]) {   // 三种都出现了
				int mx = max({cnt[1], cnt[2], cnt[3]});
				int mn = min({cnt[1], cnt[2], cnt[3]});
				if (mx - mn <= 1)               // 最大计数 - 最小计数 ≤ 1
					ans = max(ans, j - i + 1);
			}
		}
	}
	cout << ans << "\n";
}
