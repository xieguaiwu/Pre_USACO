#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int >> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < N; ++i) {
		cout << a[i].second << " \n"[i == N - 1];
	}
	long long total = 0;
	for (int i = 0; i < N; ++i) {
		total += (long long)a[i].first * (N - 1 - i);
	}
	cout << fixed << setprecision(2) << (double)total / N << "\n";
}
