#include <bits/stdc++.h>
using namespace std;

int dp[10004];
int coin[10004];

int n, k;

int main() {
	cin >> n >> k;

	dp[0] = 1;

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}

	cout << dp[k];

	return 0;
}