#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int score = 0;

    for (int i = 0; i < s.size(); i++) {
        // ')' 가 더 많아진 상황
        if (score < 0) {
            answer = false;
            break;
        }

        if (s[i] == '(') {
            score += 1;
        }
        else if (s[i] == ')') {
            score -= 1;
        }
    }

    // 짝이 맞지 않는 상황
    if (score != 0) {
        answer = false;
    }

    return answer;
}