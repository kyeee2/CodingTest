#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int edges[51][51] = { 0 };
int dist[51] = { 0 };

// 다익스트라 알고리즘 사용!
void Dijkstra(int start, int N) {
    priority_queue<pair<int, int>> pq; // 거리, 노드번호

    dist[start] = 0; // 시작점은 0으로 세팅
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int node = pq.top().second;
        int distance = -1 * pq.top().first;
        pq.pop();

        for (int i = 1; i <= N; i++) {
            if (edges[node][i] > 0) {
                if (distance + edges[node][i] < dist[i]) {
                    dist[i] = distance + edges[node][i];
                    // 가중키를 -로 넣는 이유는 우선순위가 기본적으로 내림 차순이라서
                    pq.push(make_pair(-1 * dist[i], i));
                }
            }
        }
    }

}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (int i = 0; i < road.size(); i++) {
        int n1 = road[i][0], n2 = road[i][1];
        if (edges[n1][n2] == 0) { // 아직 가중치가 없다면
            edges[n1][n2] = road[i][2];
            edges[n2][n1] = road[i][2];
        }
        else { // 가중치가 이미 있다면 더 작은 가중치 넣기
            if (edges[n1][n2] > road[i][2]) {
                edges[n1][n2] = road[i][2];
                edges[n2][n1] = road[i][2];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        dist[i] = 214700000; // 거리 무제한으로 설정
    }

    Dijkstra(1, N);

    for (int i = 1; i <= N; i++) {
        if (dist[i] <= K) answer++;
    }

    return answer;
}