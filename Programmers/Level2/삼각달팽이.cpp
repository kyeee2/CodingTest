#include <string>
#include <vector>
#include <iostream>

using namespace std;

// n, n-1, n-2....., 1개씩 채우고 방향이 바뀌는 것에 힌트를 얻음! -> n을 줄여나가며 채우기
vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int> > temp(n + 1, vector<int>(n + 1, 0)); // 2차원 벡터 생성

    int n_copy = n;
    int r = 0, c = 0; // r: 행, c: 열
    int num = 1; // 칸에 입력할 숫자
    int status = 0;  // status가 0이면 왼쪽 아래로, 1이면 오른쪽으로, 2면 왼쪽 위로
    int cnt = 1; // 현재 방향으로 몇 번 이동하였는가?

    while (1) {
        if (n == 0) {
            // n 이 0이면 삼각형 다 채움
            break;
        }
        // 현재 위치에 숫자 넣기
        temp[r][c] = num;
        num++;

        switch (status) {
        case 0:
            if (cnt == n) { 
                status = (status + 1) % 3; // status 변경
                n--; 
                cnt = 1;
                // 현재 위치를 옮겨주기
                c++;
            }
            else {
                r++;
                cnt++;
            }
            break;
        case 1:
            if (cnt == n) {
                status = (status + 1) % 3;
                n--;
                cnt = 1;
                // 현재 위치를 옮겨주기
                r--;
                c--;
            }
            else {
                c++;
                cnt++;
            }
            break;
        case 2:
            if (cnt == n) { 
                status = (status + 1) % 3;
                n--;
                cnt = 1;
                // 현재 위치를 옮겨주기
                r++;
            }
            else {
                r--;
                c--;
                cnt++;
            }
            break;
        }
    }

    for (int i = 0; i < n_copy; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(temp[i][j]);
        }
    }

    return answer;
}