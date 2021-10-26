#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int mmax = 0; // 최대 던전 방문 수
int ch[8] = { 0 };

void DFS(vector<vector<int>> dungeons, int k, int cnt) {
    for (int i = 0; i < dungeons.size(); i++) {
        if (ch[i] == 0 && k >= dungeons[i][0]) {
            ch[i] = 1;
            DFS(dungeons, k - dungeons[i][1], cnt + 1);
            ch[i] = 0;
        }
    }

    if (cnt > mmax) {
        mmax = cnt;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;

    DFS(dungeons, k, 0);

    return mmax;
}