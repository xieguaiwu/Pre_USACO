// Created on iPad.

#include <iostream>
using namespace std;

int main() {
    int A, B, X, Y;
    cin >> A >> B >> X >> Y;
    
    int L1 = min(A, B);
    int R1 = max(A, B);

    int overlap_start = max(L1, X);
    int overlap_end = min(R1, Y);

    

    return 0;
}

vector<int> count(M+1, 0);

int p, s;
cin >> p >> s;
count[p]++;
if (p != s) {
    count[s]++;
}

int max_happy = 0;
for (int i = 1; i < M; i++) {
    max_happy = max(max_happy, count[i]);
}


int N;
cin >> N;
string s;
cin >> s;

//记录现有牛的位置
vecotor<int> pos;
for (int i=0; i<N; i++) {
    if (s[i] == '1') {
        pos.push_back(i);
    }
}

//计算现有的最小间距
int current_min_dis = N + 1;
for (size_t i = 0; i < pos.size() - 1; i ++) {
    current_min_dis = min(current_min_dis, pos[i+1] - pos[i]);
}

//计算各个空隙能提供的间距
int left_gap = pos[0]; //最左侧空位
int right_gap = (N-1) - pos.back(); //最右侧空位

int max_mid_gap = 0;
for (size_t i = 0; i < pos.size() - 1; i++){
    // 放中间能得到的间距是原距离的一半向下取整
    int gap = (pos[i+1] - pos[i]) / 2;
    max_mid_gap = max(max_mid_gap, gap);
}

// 找到最佳插入位置能提供的最大间距
int best_gap = max({left_gap, right_gap, max_mid_gap});



