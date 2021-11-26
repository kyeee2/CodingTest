#include <string>
#include <vector>

using namespace std;

int cnt = 1, answer = 0;
vector<string> alpha = { "A", "E", "I", "O", "U" };

// 모든 경우 탐색
void DFS(string w, string word) {
    if (w == word) {
        answer = cnt;
        return;
    }
    else if (w.size() > 5) {
        return;
    }
    else {
        cnt++;
        for (auto ch : alpha) {
            DFS(w + ch, word);
        }
    }
}

int solution(string word) {

    for (auto ch : alpha) {
        DFS(ch, word);
    }

    return answer;
}