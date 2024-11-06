#include <bits/stdc++.h>
using namespace std;

int n, m, k, t, a, b;

// �ð� �� ��� count �迭
int cnt[301];
// use�ð�, ��� ��
vector<pair<int, int>> v;
// ����v�ε���, ������ ģ��
int dp[301][301];

// �ε���, ���� ģ��, ������ ���
int go(int here, int num, int prev) {
	if (here == v.size()) return 0;

	int& ret = dp[here][num];
	if (ret) return ret;

	// �ð� �� �ʿ��� ������ ģ�� ��
	int cost = max(0, t - v[here].second);
	// ���� ������ �ʿ��� ������ ģ�� ��(���� �ݿ�)
	int real_cost = (prev >= cost) ? 0 : cost - prev;

	ret = dp[here][num];
	if (cost == 0) prev = 0;

	//������ ģ���� �����ϸ�
	if (num - real_cost >= 0) {
		ret = max(go(here + 1, num - real_cost, cost) + v[here].first,
			go(here + 1, num, prev)) ;
	}
	// �Ұ� �ϸ�
	else
		ret = go(here + 1, num, 0);
	return ret;

}

int main() {
	cin >> n >> m >> k >> t;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		for (int j = a; j < b; j++) {
			cnt[j] = min(t, cnt[j] +1);
		}
	}

	int temp = cnt[1];
	int count = 1;

	for (int i = 2; i <= n; i++) {
		if (temp != cnt[i]) {
			v.push_back({ count, temp });
			count = 0;
			temp = cnt[i];
		}
		count++;
	}
	v.push_back({ count, temp });

	cout << go(0, k, 0);



	return 0;
}
