#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> answer;
int ch[10001];

// 테스트 1, 2번 틀려서 구글링.. => 끊긴건 생각하지 않음 ex) 1 → 2, 1 → 3, 3 → 1 인 케이스
bool DFS(string city, vector<vector<string>> tickets, int cnt, int size) {
    if (cnt == size) { // 다 돌았으면 끝내기
        return true;
    }

    for (int i = 0; i < size; i++) {
        if (city == tickets[i][0] && ch[i] == 0) { // 출발지와 탐색여부 체크
            answer.push_back(tickets[i][1]);
            ch[i] = 1;
            bool ck = DFS(tickets[i][1], tickets, cnt + 1, size);
            if (ck) return true;
            ch[i] = 0;
        }
    }
    answer.pop_back(); // 끊긴거니까 마지막 도착지 제거해주기
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());

    answer.push_back("ICN");
    DFS("ICN", tickets, 0, tickets.size());

    return answer;
}