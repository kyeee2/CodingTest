#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> Q; // <- 오름차순  less<int> or greater<int>

    // 모든 스코빌 지수 우선순위 큐에 넣기
    for (int i = 0; i < scoville.size(); i++) {
        Q.push(scoville[i]);
    }

    // 모든 스코빌 지수가 K이상이 될때까지
    while (Q.top() < K) {
        int sco = Q.top();
        Q.pop();

        // 더이상 스코빌 지수가 없다면 
        // 모든 스코빌 지수를 K이상으로 만들지 못하는 것이다.
        if (Q.empty()) {
            return -1;
        }

        // 스코빌 지수 갱신
        sco = sco + Q.top() * 2;
        Q.pop();

        Q.push(sco);
        answer++;
    }

    return answer;
}