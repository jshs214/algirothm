#include <bits/stdc++.h>
using namespace std;

int n, w, v, k;
vector<pair<int, int>> bb;
int dp[100004][104];

int go(int weight, int idx) {
	if (idx == n || weight == 0)  return 0;

	int& ret = dp[weight][idx];
	if (ret != -1) return ret;

	// ���� ���ϴ� ��� ���� idx
	ret = go(weight, idx + 1);
	
	if (weight - bb[idx].first >= 0) {
		// ���� ���ϴ� ret�� �����ϴ� go�� ��
		ret = max(ret, go(weight - bb[idx].first, idx + 1) + bb[idx].second);
	}
	

	return ret;
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		bb.push_back({ w,v });
	}

	memset(dp, -1, sizeof(dp));

	cout << go(k, 0);

	return 0;
}
