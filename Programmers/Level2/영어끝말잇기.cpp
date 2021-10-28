#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> word;   // 말한 단어
    vector<int> cnt(n); // n-1번째 사람의 차례 횟수
    int i = 1;          // 몇 번째 단어인가?

    // 첫단어는 무조건 넣기
    cnt[0]++;
    word.insert(words[0]);

    for (i = 1; i < words.size(); i++) {
        cnt[i % n]++; // 횟수 하나 올려주기

        if (words[i - 1][words[i - 1].size() - 1] != words[i][0]
            || word.find(words[i]) != word.end()) {
            // 이전 마지막 글자와 현재 첫 글자가 다르거나 이미 word에 있다면
            break;
        }
        else if (word.find(words[i]) == word.end()) {
            // 현재 단어가 word에 없다면
            word.insert(words[i]);
        }
    }

    if (i == words.size()) {
        // 탈락자가 없음
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(i % n + 1);
        answer.push_back(cnt[i % n]);
    }

    return answer;
}