#include <bits/stdc++.h>
using namespace std;

int _start, _end, n, idx, ret =1;
vector<pair<int, int>> v;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> _start >> _end;
		v.push_back({ _end, _start});
	}

	// _end ��, ������ �ð� ���� ����
	sort(v.begin(), v.end());

	_start = v[0].second;
	_end = v[0].first;

	for (int i = 1; i < n; i++) {
		// ���� �л� start�ð��� ���� �л� end�ð����� ������ ��� �Ұ�
		if (v[i].second < _end) continue;

		_start= v[i].second;
		_end = v[i].first;
		ret++;
	}
	cout << ret << '\n';

	return 0;
}