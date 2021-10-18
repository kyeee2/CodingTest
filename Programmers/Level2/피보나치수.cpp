#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int Fibonacci[100001];

    Fibonacci[0] = 0;
    Fibonacci[1] = 1;

    for (int i = 2; i <= n; i++) {
        Fibonacci[i] = (Fibonacci[i - 2] + Fibonacci[i - 1]) % 1234567;
    }

    return Fibonacci[n];
}