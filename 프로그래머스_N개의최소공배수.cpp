#include <string>
#include <vector>

using namespace std;

// �ִ����� ���ϱ�
int gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    }
    else {
        return gcd(y, x % y);
    }
}

int solution(vector<int> arr) {

    int g = gcd(arr[0], arr[1]);    // �ִ�����
    int lcm = arr[0] * arr[1] / g;  // �ּҰ����

    for (int i = 2; i < arr.size(); i++) {
        // ���� �ּҰ������ i��° ���� �ִ����� ã��
        g = gcd(lcm, arr[i]);
        // �ּҰ���� ����
        lcm = lcm * arr[i] / g;
    }

    return lcm;
}