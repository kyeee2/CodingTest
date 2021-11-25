#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <climits> // LLONG_MAX, LLONG_MIN 을 가짐

using namespace std;

// long long으로 계산 안해서 27, 28, 29가 계속 틀렸다
vector<string> solution(vector<vector<int>> line) {
    set<pair<long long, long long>> points;
    long long minX = LLONG_MAX, minY = LLONG_MAX, maxX = LLONG_MIN, maxY = LLONG_MIN;

    for (int i = 0; i < line.size() - 1; i++) {
        for (int j = i + 1; j < line.size(); j++) {
            // 계수 뽑아내기
            long long a = line[i][0];
            long long b = line[i][1];
            long long e = line[i][2];

            long long c = line[j][0];
            long long d = line[j][1];
            long long f = line[j][2];

            long long def = a * d * 1LL - b * c * 1LL;
            long long Xnum = b * f * 1LL - e * d * 1LL;
            long long Ynum = e * c * 1LL - a * f * 1LL;

            // 평행이거나 일치하면
            if (def == 0) continue;

            // x가 정수가 아님
            if (Xnum % def != 0) continue;

            // y가 정수가 아님
            if (Ynum % def != 0) continue;

            // 교점 찾기
            long x = Xnum / def;
            long y = Ynum / def;

            points.insert(make_pair(x, y));

            if (x < minX) minX = x;
            if (x > maxX) maxX = x;
            if (y < minY) minY = y;
            if (y > maxY) maxY = y;
        }
    }

    // 일단 모두 '.' 으로 채우기
    string row = string(maxX - minX + 1, '.');   // <- 이 표현 기억해두기
    vector<string> answer(maxY - minY + 1, row);

    // 교점인 부분만 '*'로 바꾸기  <- 힌트 얻음
    for (auto point : points) {
        long y = point.first - minX;
        long x = maxY - point.second;

        answer[x][y] = '*';
    }

    return answer;
}