#include<bits/stdc++.h>
using namespace std;

#define X1 0
#define Y1 1
#define X2 2
#define Y2 3

int board1[4], board2[4], truck[4];
int total;

int cal_b(int part1[4], int part2[4]) {//p1 for board, p2 for truck
	int x1in = max(part1[X1], part2[X1]);//pick the larger one
	int x2in = min(part1[X2], part2[X2]);
    int y1in = max(part1[Y1], part2[Y1]);
	int y2in = min(part1[Y2], part2[Y2]);

	if (x1in >= x2in || y1in >= y2in) return 0;
	else return (x2in - x1in) * (y2in - y1in);//and then process intergration
}

int main() {
	for (int i = 0; i < 4; ++i) {
		cin >> board1[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> board2[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> truck[i];
	}
	total = (board1[X2] - board1[X1]) * (board1[Y2] - board1[Y1]) + (board2[X2] - board2[X1]) * (board2[Y2] - board2[Y1]);

	total -= cal_b(board1, truck);
	total -= cal_b(board2, truck);

	cout << total << "\n";
}
