#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 그래프 엣지
int edges[101][101] = { 0 };

int solution(int n, vector<vector<int>> wires) {
    int cnt1 = 0, cnt2 = 0;
    int answer = 101, diff = 0;
    queue<int> Q;

    // 간선 체크하기
    for (int i = 0; i < wires.size(); i++) {
        edges[wires[i][0]][wires[i][1]] = 1;
        edges[wires[i][1]][wires[i][0]] = 1;
    }

    // wires에 있는 연결 노드를 차례대로 끊으며 완전탐색
    for (int i = 0; i < wires.size(); i++) {
        int ch[101] = { 0 }; // 노드 방문 여부

        // i번째 노드와 연결된 노드 개수 찾기
        Q.push(wires[i][0]);
        cnt1 = 1;
        ch[wires[i][0]] = 1;

        // i번째 엣지 끊기
        edges[wires[i][0]][wires[i][1]] = 0;
        edges[wires[i][1]][wires[i][0]] = 0;

        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();

            for (int j = 1; j <= n; j++) {
                if (edges[node][j] == 1 && ch[j] == 0) {
                    Q.push(j);
                    cnt1++;
                    ch[j] = 1;
                }
            }
        }

        cnt2 = n - cnt1;
        diff = (cnt2 > cnt1) ? cnt2 - cnt1 : cnt1 - cnt2;

        if (answer > diff) {
            answer = diff;
        }

        // i번째 엣지 다시 연결해주기
        edges[wires[i][0]][wires[i][1]] = 1;
        edges[wires[i][1]][wires[i][0]] = 1;
    }

    return answer;
}