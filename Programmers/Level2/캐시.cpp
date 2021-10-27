#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    if (cacheSize == 0) return 5 * cities.size();

    queue<string> q;
    queue<string> temp;

    for (int i = 0; i < cities.size(); i++) {

        //대문자 -> 소문자 변환
        for (int j = 0; j < cities[i].length(); j++) {
            cities[i][j] = tolower(cities[i][j]);
        }

        bool find = false; // cache hit 인가?

        // q에서 temp로 원소 옮기면서 cache hit 여부 판단
        while (!q.empty()) {
            string city = q.front();
            q.pop();

            if (city == cities[i]) {
                find = true;
                while (!q.empty()) {
                    temp.push(q.front());
                    q.pop();
                }
            }
            temp.push(city);
        }
        swap(q, temp); // q에 다시 도시이름 넣기

        if (find) { // cache hit 
            answer += 1;
        }
        else { // cache miss
            if (q.size() < cacheSize) {
                q.push(cities[i]);
            }
            else {
                q.pop();
                q.push(cities[i]);
            }
            answer += 5;
        }
    }

    return answer;
}