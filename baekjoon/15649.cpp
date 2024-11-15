#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int visited[10];
void makePermutation(int k)
{
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			arr[k] = i;
			visited[i] = 1;
			makePermutation(k + 1);
			visited[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	makePermutation(0);

	return 0;
}
