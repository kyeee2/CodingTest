#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int idx = 0; // 현재 skill을 어디까지 배웟는가

    for (int i = 0; i < skill_trees.size(); i++) {
        idx = 0;

        int j = 0;
        for (j = 0; j < skill_trees[i].size(); j++) { // i번쩨 skill_trees
            if (idx >= skill.size()) { // skill을 다 배웠으면
                answer++;
                break;
            }

            // 현재 skill_trees의 스킬이 skill의 어디에 위치하는가
            int k = idx;
            for (k = idx; k < skill.size(); k++) {
                if (skill[k] == skill_trees[i][j]) {
                    break;
                }
            }
            if (k == idx) {
                idx++;
            }
            else if (k < skill.size()) {
                break;
            }
        }

        // 중간에 빠지지 않았다면 순서대로 배운것!
        if (j == skill_trees[i].size()) {
            answer++;
        }
    }

    return answer;
}