#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 크기 순으로 정렬
bool compare(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer, temp;
    vector<vector<int>> split_s;
    int n = 0;
    bool flag = true;

    // 집합들 나눠주기
    for (int i = 1; i < s.size() - 1; i++) { // 양 옆 {}는 버리기
        if (s[i] == '{') {
            flag = true;
        }
        else if (s[i] == '}') {
            // 현재까지 만든 수 temp에 넣기
            n /= 10;
            temp.push_back(n);
            n = 0; // 초기화

            // temp 를 split_s에 넣기
            split_s.push_back(temp); // 현재 집합 넣기
            temp.clear(); // temp 초기화
            flag = false;
        }
        else if (s[i] == ',') {
            if (flag) { // '{'에 진입 한 후 만난 , 라면
                // 현재 위치가 ','라면 temp 에 숫자 추가
                n /= 10;
                temp.push_back(n);
                n = 0;
            }
        }
        else {
            // 현재 위치가 숫자라면 자연수 이어 만들어주기
            n += (s[i] - '0');
            n *= 10;
        }
    }

    sort(split_s.begin(), split_s.end(), compare);

    // 여기 answer에 넣는 더 좋은 방법이 있을테니 생각해보기!!! (visited 배열 만들기도 좋은 방법)
    answer.push_back(split_s[0][0]); // 가장 처음 원소는 바로 넣기
    // 순서대로 돌기
    for (int i = 1; i < split_s.size(); i++) {
        for (int j = 0; j < split_s[i].size(); j++) {
            int k;
            for (k = 0; k < answer.size(); k++) {
                // 현재 숫자가 answer 에 있다면 break
                if (split_s[i][j] == answer[k]) {
                    break;
                }
            }
            if (k == answer.size()) {
                // 위의 반복문을 다 돌고 빠져나왔다면 answer에 없는 숫자이므로 answer 에 넣기
                answer.push_back(split_s[i][j]);
                break;
            }
        }
    }

    return answer;
}