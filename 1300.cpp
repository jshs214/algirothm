#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;

	int start = 1;
	int end = k;

	int result = -1;

	while (start <= end) {
		int cnt = 0;
		int mid = (start + end) / 2;

		// n x n ��Ŀ��� K��° ���� ���Ҹ� ã�� �� 
		// mid ������ ������ ���� �̺� Ž��
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}

		if (cnt < k) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
			result = mid;
		}
	}

	cout << result;

	return 0;
}