#include <string>
#include <stack>

using namespace std;

// https://yjyoon-dev.github.io/kakao/2020/11/09/kakao-convbrackets/  을 봤다...
bool isOK(string s) {
    int cnt = 0;

    for (char c : s) {
        if (c == '(') cnt++;
        else cnt--;

        if (cnt < 0) return false;
    }

    return cnt == 0;
}

string solution(string p) {
    if (p == "") return p;

    int cnt = 0;
    string u, v;

    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') cnt++;
        else cnt--;
        if (cnt == 0) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if (isOK(u)) return u + solution(v);

    string ret = "(" + solution(v) + ")";
    for (int i = 1; i < u.size() - 1; i++)
        ret += (u[i] == '(' ? ")" : "(");

    return ret;
}