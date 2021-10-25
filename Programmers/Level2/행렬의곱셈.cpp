#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int r1 = arr1.size();       // arr1 의 행의 개수
    int c1 = arr1[0].size();    // arr1 의 열의 개수 = arr2의 행의 개수
    int c2 = arr2[0].size();    // arr2 의 열의 개수

    for (int i = 0; i < r1; i++) {
        vector<int> temp;  // answer의 i번째 행
        for (int j = 0; j < c2; j++) {
            int sum = 0; // answer[i][j] 값
            for (int k = 0; k < c1; k++) {
                sum += arr1[i][k] * arr2[k][j];
            }
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }

    return answer;
}