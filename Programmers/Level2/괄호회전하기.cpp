#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        bool flag = true;  // 올바른 괄호 문자열인지 아닌지
        for (int j = i; j < i + s.size(); j++) {
            if (s[j % s.size()] == '(' ||
                s[j % s.size()] == '{' ||
                s[j % s.size()] == '['
                ) { // 괄호 여는 문자면 무조건 push
                st.push(s[j % s.size()]);
            }
            else if (s[j % s.size()] == ')') {
                if (st.empty() || st.top() != '(') {
                    // 스택이 비었거나 짝이 안맞으면
                    flag = false;
                    break;
                }
                else {
                    // 짝이 맞으면
                    st.pop();
                }
            }
            else if (s[j % s.size()] == '}') {
                if (st.empty() || st.top() != '{') {
                    // 스택이 비었거나 짝이 안맞으면
                    flag = false;
                    break;
                }
                else {
                    // 짝이 맞으면
                    st.pop();
                }
            }
            else if (s[j % s.size()] == ']') {
                if (st.empty() || st.top() != '[') {
                    // 스택이 비었거나 짝이 안맞으면
                    flag = false;
                    break;
                }
                else {
                    // 짝이 맞으면
                    st.pop();
                }
            }
        }
        if (flag && st.empty()) {
            // 올바른 괄호 문자열이라면 answer 1 증가
            answer++;
        }
        else {
            // 올바른 괄호 문자열이 아니라면 스택 비워주기
            while (!st.empty()) st.pop();
        }
    }

    return answer;
}