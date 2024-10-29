#include <bits/stdc++.h>
using namespace std;

int n, m, s, e;
int a[2004];

int dp[2004][2004];

int solve(int s, int e) {
	int& ret = dp[s][e];

	if (ret != -1) return ret;

	
	// 1���� ����� �Ӹ����
	if (e - s == 0) {
		ret = 1;
		return ret;
	}

	// Ȧ�� ������
	if ((e - s) % 2 == 0) {
		int idx = (s + e) / 2;
		int j = e;

		for (int i = s; i < idx; i++) {
			if (a[i] == a[j])
				ret = 1;
			else {
				ret = 0;
				break;
			}
			j--;
		}
	}
	// ¦��
	else {
		int idx = (s + e) / 2;
		int j = e;
		for (int i = s; i <= idx; i++) {
			if (a[i] == a[j]) ret = 1;
			else {
				ret = 0;
				break;
			}
			j--;
		}
	}

	return ret;
}

int main() {
	cin >> n ;

	for (int i = 1; i <= n; i++)
		cin >> a[i];


	cin >> m;

	memset(dp, -1, sizeof(dp));

	while (m--) {
		cin >> s >> e;
		cout << solve(s, e) <<'\n';
	}


	return 0;
}