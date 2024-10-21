#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Human {
	ll maxHP;
	ll curHP;
	ll atk;
};
struct Monster {
	ll hp;
	ll atk;
};

struct Input {
	ll a;
	ll b;
	ll c;
};

Human H;
Monster M;
Input input[123457];

ll n, humanAtk;

// fight() while ������ �����ϸ� �ð��ʰ�.

bool fight() {
	// ���� ������� ��
	ll turnsToKillMonster = M.hp / H.atk;
	if (M.hp % H.atk) turnsToKillMonster++;

	// ������ ���� �� (Ƚ�� * ������)
	ll turnsForMonster = (turnsToKillMonster - 1) * M.atk;

	if (H.curHP > turnsForMonster) {
		H.curHP -= turnsForMonster;
		return true;
	}
	else
		return false;

}

bool solve(ll maxHP) {
	H.maxHP = maxHP;
	H.curHP = maxHP;
	H.atk = humanAtk;

	for (int i = 0; i < n; i++) {
		if (input[i].a == 1) {
			M.atk = input[i].b;
			M.hp = input[i].c;

			if (!fight())
				return false;
		}
		else if (input[i].a == 2) {
			H.atk += input[i].b;
			H.curHP = min( H.curHP + input[i].c , H.maxHP);
			
		}
	}

	return true;
}

int main() {
	cin >> n >> humanAtk;

	for (int i = 0; i < n; i++) {
		cin >> input[i].a >> input[i].b >> input[i].c;
	}

	ll left = 1;
	ll right = 9e18;
	ll lRet = right;

	while (left <= right) {
		ll mid = (left + right) / 2;

		if (solve(mid)) {
			right = mid - 1;
			lRet = min(lRet, mid);
		}
		else
			left = mid + 1;
	}

	cout << lRet;

	return 0;
}