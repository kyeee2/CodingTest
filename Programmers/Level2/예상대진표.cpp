#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    // a가 더 클 경우 swap
    if (b < a) {
        int temp = a;
        a = b;
        b = temp;
    }

    while (true) {
        // a 가 홀수고, b가 a 다음 숫자일 경우 A와 B가 서로 붙게된다.
        if (a % 2 == 1 && a + 1 == b) {
            break;
        }

        // 번호 수정
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        answer++;
    }

    return answer;
}