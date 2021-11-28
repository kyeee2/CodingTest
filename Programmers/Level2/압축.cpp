#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    string before, now;
    int current = 27;

    // 사전 초기화
    for (int i = 0; i < 26; i++) {
        dict[string(1, 'A' + i)] = i + 1;
    }

    for (int i = 0, j = 0; i < msg.size();) {
        for (j = 1; i + j <= msg.size(); j++) {
            now = msg.substr(i, j); // 현재 가장 큰 문자열 넣어주기

            if (dict.find(now) != dict.end()) { // 사전에 있다면
                before = now;
            }
            else { // 사전에 없다면
                answer.push_back(dict[before]);
                break;
            }
        }

        // 사전에 없으면 사전에 추가
        if (dict.find(now) == dict.end()) {
            dict[now] = current;
        }
        current++;
        i += (j - 1);
    }

    answer.push_back(dict[now]);

    return answer;
}