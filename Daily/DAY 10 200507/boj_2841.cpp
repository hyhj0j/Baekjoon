#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, p; // n ���� ��, p ������ ��
    cin >> n >> p;

    vector<pair<int, int>> pitch(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pitch[i].first = x;
        pitch[i].second = y;
    }

    //first�� ���� ��
    // - ������ second ��
    //  - first�� ���� �ֵ� �߿��� second�� ū �ְ� �ִ�? �׷���
    // - �ٸ��� cnt++
    //second��
}

// ��ε�� ���� �����̴�.
// �� = �ٿ��� �ش��ϴ� ������ ������ ���� ƨ���.

// ������ ������ ������ ������ ���� ���� ������ ���� �߻�. �� ���Ҹ���
// =>��.. ���ٿ��ִ� ������ �ѹ��� ������ ������ ������,
// �� ������ �ִ� �͵� �߿��� ���� ���� ���� ���� ������ �� �ϳ��� �߻��Ѵ�?
