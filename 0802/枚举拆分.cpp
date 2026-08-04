//P3397地毯 地毯 & 二维差分
//11min 36s出第一版本 wrong
//
#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n;
	cin >> n >> m;
	int x0, x1, y0, y1;
	int rug[n][n];

	for (int i = 0; i < m; ++i) {
		cin >> x0 >> y0;
		cin >> x1 >> y1;
		for (int j = x0; j < x1; ++j) {
			for (int k = y0; k < y1; ++k) {
				rug[j][k] ++;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << rug[i][j];
		}
		cout << "\n";
	}
}
