#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 파티션 있는지 체크
bool chk_p(vector<string> place, int x1, int y1, int x2, int y2) {
    int max_x = max(x1, x2);
    int min_x = min(x1, x2);
    int max_y = max(y1, y2);
    int min_y = min(y1, y2);

    if (x1 == x2) { // '|'
        if (place[x1][max_y - 1] == 'X')
            return false;
    }
    else if (y1 == y2) { // 'ㅡ'
        if (place[max_x - 1][y1] == 'X')
            return false;
    }
    else if (max_x == x2 && max_y == y2) { // '\'
        if (place[max_x][max_y - 1] == 'X' && place[max_x - 1][max_y] == 'X')
            return false;
    }
    else if (max_x == x2 && max_y == y1) { // '/'
        if (place[min_x][min_y] == 'X' && place[max_x][max_y] == 'X')
            return false;
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    vector<pair<int, int> > points; // P의 위치 저장

    for (int i = 0; i < 5; i++) {
        points.clear();

        // 모든 P의 위치를 넣어주기
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (places[i][j][k] == 'P') {
                    points.push_back(make_pair(j, k));
                }
            }
        }

        bool flag = false; // 거리두기 확인
        for (int j = 0; j < points.size(); j++) {
            int x1 = points[j].first;
            int y1 = points[j].second;

            for (int k = j + 1; k < points.size(); k++) {
                int x2 = points[k].first;
                int y2 = points[k].second;
                int diff = abs(x1 - x2) + abs(y1 - y2);

                if (diff < 2) {
                    // 거리가 0 또는 1이면 거리두기 지키지 않음
                    flag = true;
                    break;
                }
                else if (diff == 2) {
                    // 거리가 2 이면 거리두기 확인
                    if (chk_p(places[i], x1, y1, x2, y2)) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) break;
        }
        if (flag) answer.push_back(0);
        else     answer.push_back(1);
    }

    return answer;
}