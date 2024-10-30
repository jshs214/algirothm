#include <bits/stdc++.h>
using namespace std;

int n, m, c;

int a[22];
// ���� ��, ���� �������� ����� ��,  �ִ� ����
int dp[22][1<<14][22];

int solve(int here, int useJewel, int weight) {
	if (here == m) return 0;

	int& ret = dp[here][useJewel][weight];
	if (ret) return ret;

	ret = max(ret, solve(here + 1, useJewel, c));

	// ���� ��ȸ
	for(int i = 0; i <n; i++){
		// ���� ��� check(��Ʈ����ŷ)
		bool isBeforeUse = (1 << i) & useJewel;
		// ���� ���� ���Կ� ������ �Ǵ���
		bool isCan = (weight - a[i]) >= 0;
		
		if (!isBeforeUse && isCan)
			ret = max(ret, solve(here, (1 << i) | useJewel, weight - a[i]) + 1);

	}

	return ret;
}

int main(){
	// ���� ��, ���� ��, ���� ܬ ����
	cin >> n >> m >> c;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	memset(dp, 0, sizeof(dp));
	
	cout << solve(0, 0, c);

	return 0;
}