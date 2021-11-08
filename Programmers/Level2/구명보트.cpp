#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int head = 0, tail = people.size() - 1;

    sort(people.begin(), people.end());

    while (head <= tail) {
        // 가장 가벼운 사람과 가장 무거운 사람의 합이 limit 보다 작거나 같으면 둘을 태우기
        if (people[head] + people[tail] <= limit) {
            head++;
            tail--;
        }
        else { // 아니면 가장 무거운 사람 태우기
            tail--;
        }

        // 보트 추가
        answer++;
    }

    return answer;
}