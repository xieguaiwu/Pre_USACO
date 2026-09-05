#include<bits/stdc++.h>

using namespace std;


int main() {
	char comet[7], team[7];
	cin >> comet >> team;
	long long c = 1, t = 1;
	for (int i = 0; comet[i] != '\0'; ++i) {
		c *= comet[i] - 'A' + 1;
	}
	for (int i = 0; team[i] != '\0'; ++i) {
		t *= team[i] - 'A' + 1;
	}
	if (c % 47 == t % 47) cout << "GO\n";
	else cout << "STAY\n";
}
