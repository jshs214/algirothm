#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m, s, e;
int u, v, p;
int adj[504][504];
int cost[504];

void dkikstra() {
	fill(cost, cost + 504, INF);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

	//���, ���
	pq.push({ 0, s });
	cost[s] = 0;

	while (pq.size()) {
		int here = pq.top().second;
		int here_cost = pq.top().first;
		pq.pop();

		if (cost[here] != here_cost) continue;

		for (int i = 0; i < n; i++) {
			// ������������ continue
			if (adj[here][i] == -1) continue;

			int _cost = adj[here][i];
			if (cost[i] > cost[here] + _cost) {
				cost[i] = cost[here] + _cost;

				//���� ������, ���
				pq.push({ cost[i], i});
			}

		}
	}
}
void eraseEdge() {
	queue<int>q;
	q.push(e);
	while (q.size()) {
		int cx = q.front(); q.pop();

		for (int i = 0; i < n; i++) {
			// �ִܰŸ� ��� == ������ + �ִܰŸ����� ����̸� ����ó��
			if (cost[cx] == cost[i] + adj[i][cx] && adj[i][cx] != -1) {
				adj[i][cx] = -1;
				q.push(i);
			}
		}
	}

}


int main() {
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		cin >> s >> e;
		memset(adj, -1, sizeof(adj));
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> p;
			adj[u][v] = p;
		}

		dkikstra();
		eraseEdge();
		dkikstra();

		if (cost[e] != INF)
			cout << cost[e] << "\n";
		else
			cout << -1 << "\n";

	}


	return 0;
}