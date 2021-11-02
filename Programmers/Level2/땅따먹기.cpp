#include <iostream>
#include <vector>
using namespace std;

int max(vector<int> list, int idx) {
    int max = -1, temp = idx;

    for (int i = 0; i < list.size(); i++) {
        if (i == idx) {
            continue;
        }
        if (list[i] > max) {
            temp = i;
            max = list[i];
        }
    }

    idx = temp;
    return max;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;

    for (int i = 0; i < land.size() - 1; i++) {
        // 행에서 가장 큰 값을 더하는 식으로 찾았는데 "DP"로 푸는 방법이었다
        for (int j = 0; j < 4; j++) {
            land[i + 1][j] += max(land[i], j);
            answer = max(answer, land[i + 1][j]);
        }
    }

    return answer;
}