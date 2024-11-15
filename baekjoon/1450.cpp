#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<int> v1, v2;
vector<long long> sumV1, sumV2;

// �κ����� ���ϴ� �Լ�
void calcSubsetSums(const vector<int>& arr, vector<long long>& sums) {
    int size = arr.size();
    for (int i = 0; i < (1 << size); i++) {  // 2^size ��ŭ ��� �κ����� Ž��
        long long sum = 0;
        for (int j = 0; j < size; j++) {
            if (i & (1 << j)) {  // i�� j��° ��Ʈ�� 1�̸� �ش� ���� ����
                sum += arr[j];
            }
        }
        sums.push_back(sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> c;

    // �Է��� �������� ����
    int mid = n / 2;
    v1.resize(mid);
    v2.resize(n - mid);

    for (int i = 0; i < mid; i++) cin >> v1[i];
    for (int i = 0; i < n - mid; i++) cin >> v2[i];

    // �� �迭�� �κ����� ����
    calcSubsetSums(v1, sumV1);
    calcSubsetSums(v2, sumV2);

    // sumV2�� ���� (���� Ž���� ����)
    sort(sumV2.begin(), sumV2.end());

    long long cnt = 0;
    // sumV1�� �� �κ��տ� ���� sumV2���� ������ �����ϴ� ����� ���� ã��
    for (long long s1 : sumV1) {
        cnt += upper_bound(sumV2.begin(), sumV2.end(), c - s1) - sumV2.begin();
    }

    cout << cnt << "\n";
    return 0;
}
