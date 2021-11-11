#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); i++) {
        // 짝수는 마지막 비트가 0이므로 1추가하면 답이다
        if (numbers[i] % 2 == 0) {
            answer.push_back(numbers[i] + 1);
            continue;
        }
        else {
            // 홀수는 가작 오른쪽에 있는 0비트 위치 찾아주기
            long long bit = 1;
            while (true) {
                if ((numbers[i] & bit) == 0) break; // & : 두 비트가 모두 1이면 1 아니면 0
                bit <<= 1;
            }
            bit >>= 1;

            answer.push_back(numbers[i] + bit);
        }
    }

    return answer;
}