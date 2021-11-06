#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int ch[20001] = { 0 };         // 방문 여부 체크
int dis[20001] = { 0 };        // 1번 노드로부터의 거리
int E[20001][20001] = { 0 };  // 간선 연결

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max = -1;
    queue<int> Q;

    // 간선 연결하기
    for (int i = 0; i < edge.size(); i++) {
        E[edge[i][0]][edge[i][1]] = 1;
        E[edge[i][1]][edge[i][0]] = 1;
    }

    Q.push(1);
    ch[1] = 1;

    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();

        for (int i = 2; i <= n; i++) {
            if (E[node][i] == 1 && ch[i] == 0) {
                Q.push(i);
                ch[i] = 1;

                dis[i] = dis[node] + 1;
                if (max < dis[i]) {
                    max = dis[i];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (max == dis[i]) {
            answer++;
        }
    }

    return answer;
}