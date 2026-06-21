#include<bits/stdc++.h>
using namespace std;

struct Graph {
	int position;
	Graph *next;
public:
	void setNext(Graph *set) {
		next = set;
	}
	bool hasNext() {
		return next != nullptr;
	}
};

int find_next(const Graph, int, int);
bool all_through(Graph, int);
void single_test(Graph, int, int);
bool chain(Graph, int, int);

int find_next(const Graph shit[], int start, int all) {//找最近
	int pos = shit[start].position;
	int best = start;
	int best_dist = -1;
	for (int i = 0; i < all; ++i) {
		if (i == start) continue;
		int dis = abs(pos - shit[i].position);
		if (dis < best_dist || (dis == best_dist && i < best)) {
			best_dist = dis;
			best = i;
		}
	}
	return best;
}

int counter = 0;
int subcounter = 0;
bool chain(Graph shit[], int start, int all) {
	if (shit[start].hasNext()) return false;//遇见了重复环
	else { 
        shit[start].setNext(&shit[find_next(shit, start, all)]);
        ++subcounter;
    }
	return true;
}

bool all_through(Graph shit[], int all) {
	for (int i = 0; i < all; ++i) {
		if (!shit[i].hasNext())return false;
	}
	return true;
}

void all_init(Graph shit[], int all) {
    counter = 0;
    for (int i = 0; i < all; ++i) {
        shit[i].next = nullptr;
    }
}

void single_test(Graph shit[], int start, int all) {
	int k = 0;
	while (!all_through(shit, all)) {
		if (k >= all) break;
		chain(shit, k, all);
		++k;
	}
}

int main() {
	int total;
	cin >> total;
	Graph *map = new Graph[total];
	for (int i = 0; i < total; ++i) {
		cin >> map[i].position;
	}
	for (int i = 1; i < total; ++i) {
        single_test(map, i, total);
        all_init(map, total);
    }
	//cout << min << "\n";
	delete []map;
}
