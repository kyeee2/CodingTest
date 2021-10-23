#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        int sum = 0; // 연속인 수 더한값
        int num = i; // num에 i 값 넣기
        while (sum < n) { // 더한 값이 n 보다 작을동안 반복
            sum += num;
            num++;
        }

        if (sum == n) { // 더한 값이 n 과 같다면 answer 증가
            answer += 1;
        }
    }

    return answer;
}