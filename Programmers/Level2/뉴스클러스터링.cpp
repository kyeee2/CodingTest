#include <string>
#include <map>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int cnt1 = 0, cnt2 = 0, cnt_union = 0, cnt_inter = 0;
    map<string, int> s1, s2, s_union;

    for (int i = 0; i < str1.size() - 1; i++) {
        // 소문자로 변경
        str1[i] = tolower(str1[i]);
        str1[i + 1] = tolower(str1[i + 1]);

        if (str1[i] >= 'a' && str1[i] <= 'z' && str1[i + 1] >= 'a' && str1[i + 1] <= 'z') {
            string str = str1.substr(i, 2);
            if (s1.find(str) != s1.end()) {
                s1[str]++;
                s_union[str]++;
            }
            else {
                s1[str] = 1;
                s_union[str] = 1;
            }
        }
    }

    for (int i = 0; i < str2.size() - 1; i++) {
        // 소문자로 변경
        str2[i] = tolower(str2[i]);
        str2[i + 1] = tolower(str2[i + 1]);

        if (str2[i] >= 'a' && str2[i] <= 'z' && str2[i + 1] >= 'a' && str2[i + 1] <= 'z') {
            string str = str2.substr(i, 2);
            if (s2.find(str) != s2.end()) {
                s2[str]++;
            }
            else {
                s2[str] = 1;
            }
        }
    }

    for (auto s : s1) {
        cnt1 += s.second;
    }
    for (auto s : s2) {
        // 합집합 세팅
        if (s_union.find(s.first) != s_union.end()) { // 합집합에 있으면
            if (s.second > s_union.find(s.first)->second) {
                s_union.find(s.first)->second = s.second;
            }
        }
        else {
            s_union[s.first] = s.second;
        }

        cnt2 += s.second;
    }
    for (auto s : s_union) {
        cnt_union += s.second;
    }

    cnt_inter = cnt1 + cnt2 - cnt_union; // 교집합 개수

    if ((cnt1 == 0 && cnt2 == 0) || cnt_union == 0) return 65536;
    else return int(65536 * (double(cnt_inter) / double(cnt_union)));
}