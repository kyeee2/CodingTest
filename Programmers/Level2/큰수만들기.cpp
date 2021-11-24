#include <iostream>
#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int index = -1; // 가장 최근에 찾은 큰 수의 인덱스

    for (int j = 0; j < number.length() - k; j++) {
        char max = 0;

        // 최근에 찾은 큰수의 인덱스 다음부터 탐색
        for (int i = index + 1; i <= k + j; i++) {
            if (max < number[i]) {
                index = i;
                max = number[i];
            }
        }

        answer += max;
    }

    return answer;
}