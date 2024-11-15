#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int sum(vector<int>&tree, int i) {
	int ans = 0;
	while (i>0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}
void update(vector<int>& tree, int i, int value){

	while (i < tree.size()) {
		tree[i] += value;
		i += (i & -i);
	}

}
int main() {
	cin >> n >> m >> k;

	vector<int> a(n + 1);
	vector<int> tree(n+1) ;

	int temp;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(tree, i, a[i]);
	}

	m += k;

	int t1, t2, t3;
	while (m--) {
		cin >> t1 >> t2 >> t3;
		if (t1 == 1) {
			int diff = t3 - a[t2];  // ���ο� ��(t3)�� ���� ��(a[t2])�� ����
			a[t2] = t3;  // a[t2]�� t3�� ������Ʈ
			update(tree, t2, diff);  // ���̸� update �Լ��� ����

		}
		else {
			cout << sum(tree, t3) - sum(tree, t2-1) <<"\n";
		}

	}
	

	return 0;
}
