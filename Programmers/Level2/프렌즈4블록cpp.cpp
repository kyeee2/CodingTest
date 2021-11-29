#include <string>
#include <vector>
#include <queue>

using namespace std;

int M, N;
vector<vector<bool>> v;

// 4블럭이 같은지 체크
bool check(int x, int y, vector<string> board) {
    int dx[3] = { 1, 0, 1 }, dy[3] = { 0, 1, 1 };
    for (int i = 0; i < 3; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= M || yy >= N) return false;
        if (board[x][y] != board[xx][yy]) return false;
    }

    v[x][y] = true;
    for (int i = 0; i < 3; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        v[xx][yy] = true;
    }

    return true;
}

// 구글링 했음!! 큐 사용해서 열방향으로 체크해주기
vector<string> erase(vector<string> board) {
    for (int i = 0; i < N; i++) {
        queue<char> q;
        for (int j = M - 1; j >= 0; j--) {
            if (v[j][i]) //지워야할블럭
                continue;
            q.push(board[j][i]);
        }
        for (int j = M - 1; j >= 0; j--) {
            if (q.empty())
                board[j][i] = 'x';
            else {
                board[j][i] = q.front();
                q.pop();
            }
        }
    }
    return board;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    bool flag = false;
    M = m;
    N = n;

    while (!flag) {
        // 지워야할 블럭 체크 초기화
        v = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'x') continue;

                if (check(i, j, board)) flag = true;
            }
        }

        if (!flag) break;
        board = erase(board);
        flag = false;
    }

    //answer계산
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'x')
                answer++;
        }
    }

    return answer;
}