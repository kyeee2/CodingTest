#include <string>
#include <vector>

using namespace std;

string solution(string s) {

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            continue;
        }

        // 첫 문자거나 이전 문자가 공백인 경우
        if (i == 0 || s[i - 1] == ' ') {
            if ('a' <= s[i] && s[i] <= 'z') { // 소문자면
                s[i] = s[i] - 'a' + 'A'; // 대문자로
            }
        }
        // 그 외에는
        else {
            if ('A' <= s[i] && s[i] <= 'Z') { // 대문자면
                s[i] = s[i] - 'A' + 'a'; // 소문자로
            }
        }
    }

    return s;
}