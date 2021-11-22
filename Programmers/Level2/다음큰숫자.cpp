#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 이진수로 변환
string to_binary(int n) {
    string bin = "";

    while (n > 0) {
        bin += to_string(n % 2);
        n /= 2;
    }

    return bin;
}

// 이진수의 1의 개수 세기
int count_1(string bin) {
    int cnt = 0;

    for (int i = 0; i < bin.size(); i++) {
        if (bin[i] == '1') cnt++;
    }

    return cnt;
}

int solution(int n) {
    int cnt = 0;

    cnt = count_1(to_binary(n));

    for (int num = n + 1; ; num++) {
        if (count_1(to_binary(num)) == cnt) {
            return num;
        }
    }
}