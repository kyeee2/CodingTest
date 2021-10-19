#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int cnt = 1;
    int answer;
    queue<int> queue;
    priority_queue<int> pQ;

    for (int i = 0; i < priorities.size(); i++) {
        queue.push(priorities[i]);
        pQ.push(priorities[i]);
    }

    while (!queue.empty()) {
        // 가장 앞에 있는 숫자 꺼내기
        int temp = queue.front();
        queue.pop();

        if (temp == pQ.top()) { // 지금 꺼낸 숫자가 가장 크다면
            if (location == 0) { // 현재 꺼낸 숫자가 요청한 문서라면
                answer = cnt;
                break;
            }
            else { // 현재 꺼낸 숫자가 요청한 문서가 아니라면
                cnt++;
                location--;
                pQ.pop();
            }
        }
        else { // 지금 꺼낸 숫자가 가장 크지 않다면
            if (location == 0) { // 현재 꺼낸 숫자가 요청한 문서라면
                queue.push(temp);
                location = queue.size() - 1;
            }
            else { // 현재 꺼낸 숫자가 요청한 문자가 아니라면
                queue.push(temp);
                location--;
            }
        }
    }

    return answer;
}