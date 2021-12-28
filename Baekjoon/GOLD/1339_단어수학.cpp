#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 해당 알파벳의 가중치
int alp[26] = { 0 };

// 내림차순
bool cmp(int& a, int& b) {
	return a > b;
}

int main(int argc, char** argv) {
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		int pow = 1;

		cin >> str;
		for (int j = str.size() - 1; j >= 0; j--) {
			alp[str[j] - 'A'] += pow;
			pow *= 10;
		}
	}

	sort(alp, alp + 26, cmp);

	int result = 0, num = 9;
	for (int i = 0; i < 26; i++) {
		if (alp[i] == 0) break; // 가중치가 없다면 빠져나오기

		result += num * alp[i];
		num--;
	}

	cout << result;

	return 0;
}
// 구글링으로 왜 틀렸는지 알아낼 수 있었다.


// 틀린 답안
/*
	틀린 이유: 가장 앞에 존재하는 문자에 큰 값을 부여

	ABC
	BDA
	의 경우 A 가 9, B 가 8을 가지게 되는데
	실제로 B가 9, A가 8을 갖는 것이 더 큰 값이 된다.
*/
/*
int main(int argc, char** argv) {

	int N, max_len = 0, num = 9, sum = 0;
	string str[11];
	map<char, int> m;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
		if (str[i].size() > max_len) max_len = str[i].size() - 1;
	}

	while (max_len >= 0) {
		for (int i = 0; i < N; i++) {
			int len = str[i].size() - 1;
			if (len >= max_len) {
				if (m.find(str[i][len - max_len]) == m.end()) {
					m[str[i][len - max_len]] = num;
					num--;
				}
			}
		}
		max_len--;
	}

	for (int i = 0; i < N; i++) {
		int n = 0;
		for (int j = 0; j < str[i].size(); j++) {
			n += m[str[i][j]];
			n *= 10;
		}
		n /= 10;

		sum += n;
	}

	cout << sum;

	return 0;
}
*/