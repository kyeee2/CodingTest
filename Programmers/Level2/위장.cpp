#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> M;

    // 옷 종류 : 개수
    for (auto c : clothes) {
        M[c[1]] += 1;
    }

    // 모든 옷 종류의 개수로 조합 찾기
    for (auto m : M) {
        answer *= m.second + 1;
    }

    return answer - 1;
}