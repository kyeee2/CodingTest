#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    /*
   string str = s;

    while(str.size() > 0){
        if(str.size() % 2 == 1) {
            return 0;
        }

        // ★ 여기가 효율성이 안좋음!!! ★
        bool flag = true;
        for(int i = 0; i < str.size() - 1; i++) {
            if(str[i] == str[i + 1]) {
                str = str.substr(0, i) + str.substr(i + 2, str.size());
                flag = false;
                break;
            }
        }
        if(flag) {
            return 0;
        }

    }
   return 1;
   */

   // 효율성을 위해 스택 사용하기
    stack<char> st;

    if (s.size() <= 0) return 1; // 빈 문자열은 1 반환
    else if (s.size() % 2 == 1) return 0;  // 문자열의 길이가 홀수라면 0 반환

    // stack 이 비어있거나 가장 위의 글자와 현재 글자가 동일하지 않으면 push
    // 아니라면 pop!
    st.push(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (st.empty() || st.top() != s[i]) {
            st.push(s[i]);
        }
        else {
            st.pop();
        }
    }

    if (st.empty()) return 1;
    else           return 0;
}