#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {

	int n, m;	// n : W의 길이, m: S의 길이
	int cnt = 0;
	string W, S;
	map<char, int> alpW, alpS;

	cin >> n >> m;
	cin >> W;
	cin >> S;

	// 사용된 문자:사용된 숫자 쌍으로 저장 
	for (int i = 0; i < n; i++) {
		if (alpW.find(W[i]) != alpW.end()) {
			alpW[W[i]] += 1;
		}
		else {
			alpW[W[i]] = 1;
		}

		if (alpS.find(S[i]) != alpS.end()) {
			alpS[S[i]] += 1;
		}
		else {
			alpS[S[i]] = 1;
		}
	}

	for (int i = 0; i < m - n; i++) {
		// alpW에 있는 문자쌍이 aplS와 동일한지 체크
		bool flag = true;
		for (auto alp : alpW) {
			char ch = alp.first;
			int num = alp.second;

			if (alpS.find(ch) == alpS.end()) { // alpS에 없으면 
				flag = false;
				break;
			}
			else {
				if (alpS[ch] != num) { //  있는데 개수가 다르면 
					flag = false;
					break;
				}
			}
		}
		if (flag) cnt++;

		// 문자 바꿔주기
		char ori_ch = S[i], new_ch = S[i + n];
		// S의 가장 앞의 문자 지우기 
		if (alpS[ori_ch] == 1) {
			alpS.erase(ori_ch);
		}
		else {
			alpS[ori_ch] -= 1;
		}
		// 새로 추가될 문자 추가 
		if (alpS.find(new_ch) != alpS.end()) {
			alpS[new_ch] += 1;
		}
		else {
			alpS[new_ch] = 1;
		}
	}
	// 마지막에 바꾸고 체크 안해서 계속 틀림
	// -> 이렇게 지저분하게 말고 어떻게 깨끗하게 할 수 있는지 생각해보기
	bool flag = true;
	for (auto alp : alpW) {
		char ch = alp.first;
		int num = alp.second;

		if (alpS.find(ch) == alpS.end()) { // alpS에 없으면 
			flag = false;
			break;
		}
		else {
			if (alpS[ch] != num) { //  있는데 개수가 다르면 
				flag = false;
				break;
			}
		}
	}
	if (flag) cnt++;

	cout << cnt;

	return 0;
}
