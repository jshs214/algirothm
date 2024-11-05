#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, k;

ll sum(vector<ll> &tree, int i) {
	ll ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= (i & -i);
	}

	return ret;
}
void update(vector<ll>& tree, int i, ll value) {
	while (i < tree.size()) {
		tree[i] += value;
		i += (i & -i);
	}
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<ll> a(n + 1);
	vector<ll> tree(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(tree, i, a[i]);
	}
	m += k;

	while (m--) {
		int t1;
		cin >> t1;

		// b��°�� c�� �ٲ�
		if (t1 == 1) {
			int t2;
			ll t3;
			cin >> t2 >> t3;

			// ���� ���� �� ���� ����
			ll diff = t3 - a[t2];


			a[t2] = t3;				// �� �迭 update
			update(tree, t2, diff);	//���� �� tree update
		}
		else {
			int t2, t3;
			cin >> t2 >> t3;
			cout << sum(tree, t3) - sum(tree, t2 - 1)<<'\n';
		}



	}

}