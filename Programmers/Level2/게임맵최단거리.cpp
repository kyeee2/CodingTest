#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size(), m = maps[0].size();            // n: 세로, m: 가로 길이
    int road[100][100] = { 0 };                           // (i, j)까지 가는데 최소 거리
    int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };   // 위에서부터 시계방향
    queue<pair<int, int>> Q;                            // 지나간 좌표 큐

    Q.push(make_pair(0, 0)); // (0, 0) 에서 시작
    road[0][0] = 1;          // 최소거리 갱신
    maps[0][0] = 0;          // 지나갔으면 벽으로 만들기
    while (!Q.empty()) {
        pair<int, int> point = Q.front();
        Q.pop();
        int x = point.first;
        int y = point.second;

        for (int i = 0; i < 4; i++) {  // 상하좌우 살펴보기
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx >= 0 && xx < n && yy >= 0 && yy < m && maps[xx][yy] == 1) {  // 안지나간 길이면
                road[xx][yy] = road[x][y] + 1;  // 최소거리 갱신

                Q.push(make_pair(xx, yy));
                maps[xx][yy] = 0; // 벽으로 만들기
            }
        }
    }

    if (road[n - 1][m - 1] == 0) return -1;
    else                    return road[n - 1][m - 1];
}