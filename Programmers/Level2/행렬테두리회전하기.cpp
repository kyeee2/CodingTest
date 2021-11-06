#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int arr[101][101] = { 0 };
    int n = 1;

    // 배열 채우기
    for (int i = 1; i <= rows; i++) { // index 1부터 시작하기
        for (int j = 1; j <= columns; j++) {
            arr[i][j] = n;
            n++;
        }
    }

    for (int i = 0; i < queries.size(); i++) {
        cout << i << "번째" << endl;
        int min = 20000;

        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];

        // → ↓ ← ↑ 방향으로 진행하기
        // → 방향
        int temp = arr[x1][y2];
        if (min > arr[x1][y2]) {
            min = arr[x1][y2];
        }
        for (int y = y2; y > y1; y--) {
            arr[x1][y] = arr[x1][y - 1];
            if (min > arr[x1][y - 1]) {
                min = arr[x1][y - 1];
            }
        }
        int num = temp; // 오른쪽 위애 꼭지점 숫자 저장

        // ↓ 방향
        temp = arr[x2][y2];
        if (min > arr[x2][y2]) {
            min = arr[x2][y2];
        }
        for (int x = x2; x > x1 + 1; x--) {
            arr[x][y2] = arr[x - 1][y2];
            if (min > arr[x - 1][y2]) {
                min = arr[x - 1][y2];
            }
        }
        arr[x1 + 1][y2] = num;
        num = temp; // 오른쪽 아래 꼭지점 숫자 저장

        // ← 방향
        temp = arr[x2][y1];
        if (min > arr[x2][y1]) {
            min = arr[x2][y1];
        }
        for (int y = y1; y < y2 - 1; y++) {
            arr[x2][y] = arr[x2][y + 1];
            if (min > arr[x2][y + 1]) {
                min = arr[x2][y + 1];
            }
        }
        arr[x2][y2 - 1] = num;
        num = temp; // 왼쪽 아래 꼭지점 숫자 저장

        // ↑ 방향
        arr[x1][y1 + 1] = arr[x1][y1];
        if (min > arr[x1][y1]) {
            min = arr[x1][y1];
        }
        for (int x = x1; x < x2 - 1; x++) {
            arr[x][y1] = arr[x + 1][y1];
            if (min > arr[x + 1][y1]) {
                min = arr[x + 1][y1];
            }
        }
        arr[x2 - 1][y1] = num;

        answer.push_back(min);
    }

    return answer;
}