#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct {
	int node1;
	int node2;
	int weight;
} computer;

bool compare(computer a, computer b) {
	return a.weight < b.weight;
}

int par[1001]; // 부모 노드

int find(int n) {
	if (par[n] == n) return n;
	else {
		return find(par[n]);
	}
}

// MST 문제  <- dfs로 풀었다가 틀려서 구글링....
int main() {
	int N, M, cost = 0;
	int ch[1001] = { 0 };
	vector<computer> computers;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		computer C;
		cin >> C.node1 >> C.node2 >> C.weight;

		computers.push_back(C);
	}

	sort(computers.begin(), computers.end(), compare);  //  비용 오른차순 

	// 크루스칼 알고리즘
	for (int i = 1; i <= N; i++) par[i] = i;

	for (auto com : computers) {
		// 연결이 안되어 있으면 
		if (find(com.node1) != find(com.node2)) {
			// 연결해주기
			par[find(com.node1)] = find(com.node2);
			cost += com.weight;
		}
	}

	cout << cost;

	return 0;
}