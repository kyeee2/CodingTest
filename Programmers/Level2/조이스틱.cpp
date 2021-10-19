#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int i = 0, count = 0, size = name.size();
    string Name(size, 'A'); // <-- A로만 이루어진 길이가 size인 문자열 만들기

    while (true) {
        // 현재 위치의 값이 다르면
        if (name[i] != Name[i]) {
            if (name[i] - Name[i] <= 13) {
                count += name[i] - 'A';
            }
            else {
                count += 'Z' - name[i] + 1;
            }
            Name[i] = name[i];
        }

        // 이름이 같아졋다면
        if (name == Name)
            return count;

        // 다른 문자의 위치 찾기
        for (int move = 1; move < size; move++) {
            // 오른쪽이 빠르면
            if (name[(i + move) % size] != Name[(i + move) % size]) {
                i = (i + move) % size;
                count += move;
                break;
            }
            // 왼쪽이 빠르면
            else if (name[(i - move + size) % size] != Name[(i - move + size) % size]) {
                i = (i - move + size) % size;
                count += move;
                break;
            }
        }
    }
}