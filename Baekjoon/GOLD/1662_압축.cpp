#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<int> st;
    string str;
    cin >> str;

    for (int i = str.size() - 1; i >= 0; i--) {
        if ('0' <= str[i] && str[i] <= '9')
            st.push(1);
        else if (str[i] == ')')
            st.push(-1);
        else if (str[i] == '(') {
            i--;
            int num = str[i] - '0';

            int len = 0;
            while (!st.empty() && st.top() != -1) {
                len += st.top();
                st.pop();
            }
            st.pop();

            len *= num;
            st.push(len);
        }
    }

    int total = 0;
    while (!st.empty()) {
        total += st.top();
        st.pop();
    }
    cout << total;
    return 0;
}
