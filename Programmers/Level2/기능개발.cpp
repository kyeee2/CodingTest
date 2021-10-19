#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;

    for (int i = 0; i < progresses.size(); i++) {
        // 99 에서 빼는게 포인트
        int day = (99 - progresses[i]) / speeds[i] + 1;

        days.push(day);
    }

    // 가장 처음 날짜 빼기
    int max_day = days.front();
    days.pop();
    int cnt = 1;
    while (!days.empty()) {
        if (max_day < days.front()) {
            answer.push_back(cnt);
            max_day = days.front();
            cnt = 1;
        }
        else {
            cnt++;
        }
        days.pop();
    }
    answer.push_back(cnt);

    return answer;
}