#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	string sender = "";
	string names[n];
	string Nnames[n];
	int geben = 0; //amount of money
	int givenum = 0; // amount of people
	map<string, int> total;

	for (int i = 0; i < n; ++i) {
		cin >> names[i];
		total[names[i]] = 0;
	}

	for (int i = 0; i < n; ++i) {
		cin >> sender >> geben >> givenum;
		int avg = geben > 0 ? geben / givenum : 0;
		int meingeld = geben > 0 ? geben - givenum * avg : 0;
		total[sender] += meingeld - geben;
		for (int j = 0; j < givenum; ++j) {
			cin >> Nnames[j];
			total[Nnames[j]] += avg;
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << names[i] << " " << total[names[i]] << "\n";
	}
}
