#include <vector>
#include <queue>

using namespace std;

// BFS 사용하기!
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    queue<pair<int, int>> Q;
    int row = picture.size(), col = picture[0].size(); // 행, 열 크기
    int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };  // 상하좌우

    int number_of_area = 0;       // 영역의 개수
    int max_size_of_one_area = 0; // 가장 큰 영역의 크기
    int size = 0, num = 0;        // 영역의 크기, 그림의 숫자 (1, 2, ...)

    // 전체 탐색
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // i행 j열의 원소가 그림일 때
            if (picture[i][j] > 0) {
                Q.push(make_pair(i, j));
                num = picture[i][j];
                picture[i][j] = 0;
                number_of_area++;
                size = 1;
            }

            // 큐가 빌때까지 => BFS
            while (!Q.empty()) {
                pair<int, int> point = Q.front();
                Q.pop();
                int x = point.first;
                int y = point.second;

                // 상하좌우 탐색
                for (int k = 0; k < 4; k++) {
                    int xx = x + dx[k];
                    int yy = y + dy[k];
                    if (xx >= 0 && xx < row && yy >= 0 && yy < col && picture[xx][yy] == num) {
                        Q.push(make_pair(xx, yy));
                        picture[xx][yy] = 0;
                        size++;
                    }
                }
            }

            // 현재 그림의 크기가 가장 크다면
            if (max_size_of_one_area < size) {
                max_size_of_one_area = size;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}