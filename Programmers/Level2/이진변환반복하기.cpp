#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int total = 0, cnt = 0;

    while (s.size() > 1) {
        string temp = "";
        int cnt0 = count(s.begin(), s.end(), '0');  // 문자열에서 0의 개수 세기
        total += cnt0;

        while (temp.size() < (s.size() - cnt0)) {
            temp += "1";
        }

        int num = temp.size();
        s = "";
        while (num > 0) {
            s += to_string(num % 2);
            num /= 2;
        }
        cnt++;
    }

    answer.push_back(cnt);
    answer.push_back(total);
    return answer;
}