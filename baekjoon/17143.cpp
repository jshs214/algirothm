#include <bits/stdc++.h>
using namespace std;

//           ��  �� �� ��
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
    // (y, x)�� ���� ū ����� ���� ���� (size, index)
    pair<int, int> a[104][104];
    memset(a, -1, sizeof(a)); // -1�� �ʱ�ȭ

    // ��� ��� �̵�
    for (int i = 0; i < v.size(); i++) {
        int y = v[i].y;
        int x = v[i].x;
        int speed = v[i].speed;
        int dir = v[i].dir;

        // �ӵ� ����ȭ
        if (dir <= 1) speed %= (2 * (R - 1));
        else speed %= (2 * (C - 1));

        // ��� �̵�
        for (int j = 0; j < speed; j++) {
            y += dy[dir];
            x += dx[dir];

            // ��� ������ ������ ���� ��ȯ
            if (y < 0 || y >= R) {
                ChangeDirection(dir);
                y += dy[dir] * 2;
            }
            if (x < 0 || x >= C) {
                ChangeDirection(dir);
                x += dx[dir] * 2;
            }
        }

        // �̵� �Ϸ�� ��ġ ����
        v[i].y = y;
        v[i].x = x;
        v[i].dir = dir;

        // �ش� ��ġ�� ���� ���� ���Ͽ� �� ū �� �����
        if (a[y][x].first == -1 || v[i].size > v[a[y][x].second].size) {
            a[y][x] = { v[i].size, i }; // �� ū ��� ���� ����
        }
    }

    // �ߺ��� ��� ����
    vector<shark> new_v;  // ��Ƴ��� �� ������ ����
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (a[i][j].first != -1) {
                new_v.push_back(v[a[i][j].second]);
            }
        }
    }
    v = new_v;  // ��Ƴ��� �� ���� ���Ϳ� �ݿ�
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

        // 2d array�� �ð� ����
		MoveShark();  // ��� �̵�
	}

	cout << ret;

	return 0;
}