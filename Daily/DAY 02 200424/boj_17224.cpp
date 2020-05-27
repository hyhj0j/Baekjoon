// APC�� �� �����½�ũ ��ȸ�� �Ǿ�����? ( https://www.acmicpc.net/problem/17224 )
// (100/140) : SUB1, SUB2 �� ���ư��µ� �� SUB1�� �� ���� ���� ���� ��;

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)     // �ι�°�� ������
        return a.first < b.first; // ù��°�� �����̵� �����̵� ������� �׷��� ��������<������. �����϶�>�̰���.
    return a.second < b.second;   // �ι�°�� ������ ��������<���� �����ؾߵ�
}

int main()
{
    int n, l, k;
    cin >> n >> l >> k;
    pair<int, int> sub[n];
    for (int i = 0; i < n; i++)
    {
        cin >> sub[i].first >> sub[i].second;
    }

    int total = 0;
    int cnt = 0;

    sort(sub, sub + n, compare);

    for (int i = 0; i < n; i++)
    {
        if (sub[i].second <= l)
        {
            total += 140;
            cnt++;
        }
        else if (sub[i].first <= l && sub[i].second > l)
        {
            total += 100;
            cnt++;
        }
        if (cnt >= k)
            break;
    }

    cout << total;
}

// �ϴ� ������ l üũ�ؼ� ���� �ذ�
// ����� ���� �ذ������� �� ������ ���� �� �Ű澲����
// ����� l üũ�ؼ� �� l �����ΰ� Ǯ��
// �̶� k �� �ʰ��Ƴ� Ȯ���ؾߵ�