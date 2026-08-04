//P8218 【深进1.例1】求区间和
//第一次做此类题型，起码花了三十分钟然后出了程序，但因为不懂partial_sum函数的语法而不得不让ai调试才出了结果
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n;
	vector<int> list(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> list[i];
	}
	cin >> m;
	vector<int> L(m), Lsum(m), R(m), Rsum(m);
	vector<int> s(n + 1, 0);
	partial_sum(list.begin(), list.end(), s.begin() + 1);
	for (int i = 0; i < m; ++i) {
		cin >> L[i] >> R[i];
		Lsum[i] = s[L[i] - 1];
		Rsum[i] = s[R[i]];
	}


	for (int i = 0; i < m; ++i) {
		cout << Rsum[i] - Lsum[i] << "\n";
	}
}
