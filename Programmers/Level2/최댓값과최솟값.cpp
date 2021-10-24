#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    int mmin = 21470000, mmax = -21470000, now;
    string answer = "", temp;
    stringstream str(s); // str 에 s 값 넣기

    // str을 공백 기준으로 나누기
    while (str >> temp) {
        now = stoi(temp);

        if (mmin > now) {
            mmin = now;
        }
        if (mmax < now) {
            mmax = now;
        }
    }

    answer = to_string(mmin) + " " + to_string(mmax);

    return answer;
}