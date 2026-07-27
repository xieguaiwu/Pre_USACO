#include <bits/stdc++.h>

using namespace std;

int main() {
	int Q;
	long tankcap[4];
	for (int i = 0; i < 4; ++i) {
		cin >> tankcap[i];
	}
	long tankamou[4];
	for (int i = 0; i < 4; ++i) {
		cin >> tankamou[i];
	}
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int s, d;
		cin >> s >> d;
		--s;
		--d;
		int pour = min(tankamou[s], tankcap[d] - tankamou[d]);
		tankamou[s] -= pour;
		tankamou[d] += pour;
	}
	for (int i = 0; i < 4; ++i) {
		cout << tankamou[i] << "\n";
	}
}
