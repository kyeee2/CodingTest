#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    // 최대한 순간이동을 많이 해야한다
    // => 그러기 위해서 일단 순간이동으로 현재 위치에 도착했다고 생각하자
    // => 홀수라면 순간이동으로 움직이지 못했으니까 짝수로 만들어주기
    // 계속 반복!
    while (n > 0) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            ans++;
            n -= 1;
        }
    }

    return ans;
}