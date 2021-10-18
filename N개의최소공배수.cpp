#include <string>
#include <vector>

using namespace std;

// 최대공약수 구하기
int gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    }
    else {
        return gcd(y, x % y);
    }
}

int solution(vector<int> arr) {

    int g = gcd(arr[0], arr[1]);    // 최대공약수
    int lcm = arr[0] * arr[1] / g;  // 최소공배수

    for (int i = 2; i < arr.size(); i++) {
        // 현재 최소공배수와 i번째 수의 최대공약수 찾기
        g = gcd(lcm, arr[i]);
        // 최소공배수 갱신
        lcm = lcm * arr[i] / g;
    }

    return lcm;
}