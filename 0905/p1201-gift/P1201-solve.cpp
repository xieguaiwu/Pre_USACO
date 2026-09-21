#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> names(n, nullptr);
	vector<int> geben(n, 0);
	vector<int> givenum(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> names[i] >> geben[i] >> givenum[i];
	}
}
