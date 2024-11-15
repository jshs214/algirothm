#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pSum[1000005] = { 0, };
ll mod[1005] = { 0, };

ll n, m;
ll cnt = 0;

// nP2
ll combi(ll start) {
	ll ret = 0;
	ret = start * (start - 1) / 2;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> pSum[i];
		pSum[i] += pSum[i - 1];
	}


	for (int i = 1; i <= n; i++) {
		// m���� �������� ����
		mod[pSum[i] % m]++;
	} 

	// 0 ���� mod���� ���� cnt
	cnt += mod[0];

	for (int i = 0; i < m; i++) {
		if (mod[i] > 1) {
			cnt += combi(mod[i]);
		}
	}
	

	cout << cnt;

	  

	return 0;
}