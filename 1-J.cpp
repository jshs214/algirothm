// 9375 �������ذ� �� �ȵ�
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, n2;
	cin >> n;

	string a, b;
	

	for (int i = 0; i < n; i++) {
		cin >> n2;
		
		// ��, ����(����)
		map<string, int> cloth;

		for (int j = 0; j < n2; j++) {
			cin >> a >> b;

			cloth[b]++;
		}

		long long ret = 1;
		for (auto i : cloth) {
			ret *= i.second + 1;
		}
		ret -= 1;
		cout << ret << "\n";
	}
	

}