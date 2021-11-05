#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string trans = "0";
    string num = "0123456789ABCDEF";
    int N = 1, M = 0;

    while (trans.size() <= t * m) {
        string temp = ""; // n진법 담기
        M = N;
        while (M > 0) {
            temp += num[M % n];
            M /= n;
        }
        reverse(temp.begin(), temp.end()); // 역순으로
        trans += temp;

        N++;
    }

    p--;
    for (int i = 0; i < t * m; i += m) {
        answer += trans[i + p];
    }

    return answer;
}