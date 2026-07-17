#include <bits/stdc++.h>
using namespace std;

int main() {
	int start, end, x, y;
	cin >> start >> end >> x >> y;
	int l1 = min(start, end);
	int r1 = max(start, end);

	if (x > y) swap(x, y);

	int left = max(l1, x);
	int right = min(y, r1);

	if (right - left > 0) cout << right - left << "\n";
	else cout << 0 << "\n";
}
