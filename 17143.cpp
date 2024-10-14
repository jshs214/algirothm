#include <bits/stdc++.h>
using namespace std;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

int R, C, M;

struct shark {
	int y, x, speed, dir, size;
};
// shark info
vector<shark>v;

int peopleIdx = -1;

int ret = 0;

void GetShark() {
	
	for (int i = 0; i < R; i++) {
		//���ϰ� ����� ��� ������ ��� break;
		for (int j = 0; j < v.size(); j ++) {
			if (i == v[j].y && peopleIdx == v[j].x) {
				ret += v[j].size;
				v.erase(v.begin() + j);
				return;
			}
		}

	}

}
void ChangeDirection(int &dir) {
	if (dir == 0) dir = 1;
	else if (dir == 1) dir = 0;
	else if (dir == 2) dir = 3;
	else if (dir == 3) dir = 2;
}

void MoveShark() {
    // ��� ��� �̵�
    for (int i = 0; i < v.size(); i++) {
        int y = v[i].y;
        int x = v[i].x;
        int speed = v[i].speed;
        int dir = v[i].dir;

        // ��� �̵�
        for (int j = 0; j < speed; j++) {
            y += dy[dir];
            x += dx[dir];

            if (y < 0 || y >= R) {
                ChangeDirection(dir);
                y += dy[dir] * 2; // ��� ����
            }
            if (x < 0 || x >= C) {
                ChangeDirection(dir);
                x += dx[dir] * 2; // ��� ����
            }
        }

        // �̵��� ��� ��ġ ������Ʈ
        v[i].y = y;
        v[i].x = x;
        v[i].dir = dir;
    }

    // ���� ��ġ�� �ִ� ��� ó��
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i].y == v[j].y && v[i].x == v[j].x) {
                // ũ�Ⱑ ū �� ����
                if (v[i].size > v[j].size) {
                    v.erase(v.begin() + j);
                    j--;
                }
                else {
                    v.erase(v.begin() + i);
                    i--;
                    break;
                }
            }
        }
    }
}



int main() {
	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		
		shark temp = { r -1, c -1, s, d-1, z };
		v.push_back(temp);
	}

	while (++peopleIdx < C) {  // ���ò� �̵�
		GetShark();  // ��� ���
		MoveShark();  // ��� �̵�
	}

	cout << ret;

	return 0;
}