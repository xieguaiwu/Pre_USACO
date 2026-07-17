#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	int types, cows;
	cin >> types >> cows;
	vector<int> favor(types + 1, 0);
	for (int i = 0; i < cows; ++i) {
		int f1, f2;
		cin >> f1 >> f2;
		++favor[f1];
		if (f2 != f1) ++favor[f2];
	}

	int max_happy = 0;
	// BUG: i < types 遗漏 favor[types]（类型从1编号到types）
	// 修正：改为 i <= types
	for (int i = 1; i <= types; ++i) {
		max_happy = max(max_happy, favor[i]);
	}

	cout << max_happy << "\n";
}
