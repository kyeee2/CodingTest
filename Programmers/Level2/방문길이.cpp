#include <string>

using namespace std;

int ch[11][11][4] = { 0 }; // 방문 체크,  3번째 값 -> 0: U, 1: R, 2: D, 3: L

int solution(string dirs) {
    int answer = 0;
    int x = 0, y = 0;  // 현재 위치

    for (int i = 0; i < dirs.size(); i++) {
        int xx = x;
        int yy = y;
        int dir1 = 0, dir2 = 0; // dir1 : 현재 위치에서, dir2: 이동한 위치에서 방문방향

        switch (dirs[i]) {
        case 'U':
            yy += 1;
            dir1 = 0;
            dir2 = 2;
            break;
        case 'D':
            yy -= 1;
            dir1 = 2;
            dir2 = 0;
            break;
        case 'R':
            xx += 1;
            dir1 = 1;
            dir2 = 3;
            break;
        case 'L':
            xx -= 1;
            dir1 = 3;
            dir2 = 1;
            break;
        }

        if (xx > 5 || xx < -5 || yy > 5 || yy < -5) continue;  // 범위 벗어난 경우

        // 방문 안했으면 양방향 다 방문 체크 갱신, 방문길이 1추가
        if (ch[x + 5][y + 5][dir1] == 0) {
            ch[x + 5][y + 5][dir1] = 1;
            ch[xx + 5][yy + 5][dir2] = 1;
            answer++;
        }

        // 현재 위치 갱신
        x = xx;
        y = yy;
    }

    return answer;
}