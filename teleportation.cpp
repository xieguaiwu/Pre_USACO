#include<bits/stdc++.h>
using namespace std;
int main() {
	int starter, ender, port1, port2;
	cin >> starter >> ender >> port1 >> port2;
	int d1 = abs(ender - starter);
	int d2 = abs(port1 - starter) + abs(ender - port2);
	int d3 = abs(port2 - starter) + abs(ender - port1);
	int distance = min(min(d1, d2), d3);
	cout << distance;
	return distance;
}
