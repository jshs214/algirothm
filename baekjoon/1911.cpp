#include <bits/stdc++.h>
using namespace std;

int n, l, ret =0;
int cur = 0;
vector<pair<int, int>> v;
int idx, pan;

int main() {
	cin >> n >> l;
	
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < n; i ++){
		// �κ��� idx �ȿ� �� ���� ���
		if (v[i].second <= idx) continue;


		if (idx < v[i].first) {
			pan = (v[i].second - v[i].first) / l + (v[i].second - v[i].first) % l ? 1 : 0;
			idx = v[i].first + pan * l;
		}
		else {
			pan = (v[i].second - idx) / l + (v[i].second - idx) % l ? 1 : 0;
			idx = idx + pan * l;
		}
		ret += pan;

	}

	cout << ret;

	return 0;
}