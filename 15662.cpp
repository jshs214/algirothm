#include <bits/stdc++.h>
using namespace std;

#define CW 1      // �ð� ����
#define CCW -1    // �ݽð� ����

const int RIGHT = 2;
const int LEFT = 6;

int t, k;
string topni[1004];
vector<pair<int, int>> commands; // ȸ�� ��� ����

void rotateTopni(int num, int direction) {
    if (direction == CW) {
        rotate(topni[num].rbegin(), topni[num].rbegin() + 1, topni[num].rend());
    }
    else if (direction == CCW) {
        rotate(topni[num].begin(), topni[num].begin() + 1, topni[num].end());
    }
}

// ȸ�� ������ ����
vector<int> getRotationDirections(int num, int dir) {
    vector<int> directions(t + 1, 0); // �� ��Ϲ����� ȸ�� ���� ���� (0: ȸ�� �� ��)
    directions[num] = dir;

    for (int i = num; i > 1; i--) {
        if (topni[i][LEFT] != topni[i - 1][RIGHT]) {
            directions[i - 1] = -directions[i];
        }
        else {
            break;
        }
    }

    // ������ Ž��
    for (int i = num; i < t; i++) {
        if (topni[i][RIGHT] != topni[i + 1][LEFT]) {
            directions[i + 1] = -directions[i];
        }
        else {
            break;
        }
    }

    return directions;
}

int main() {
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cin >> topni[i];
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int num, dir;
        cin >> num >> dir;
        commands.push_back({ num, dir });
    }

    for (auto i: commands) {
        int num = i.first;
        int dir = i.second;

        vector<int> directions = getRotationDirections(num, dir);

        // ȸ��
        for (int i = 1; i <= t; i++) {
            if (directions[i] != 0) {
                rotateTopni(i, directions[i]);
            }
        }
    }

    int ret = 0;
    for (int i = 1; i <= t; i++) {
        if (topni[i][0] == '1') {
            ret++;
        }
    }

    cout << ret << '\n';
    return 0;
}
