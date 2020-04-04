// ���� �� �����ϴ� �κ� ���� (https://www.acmicpc.net/problem/11053)

#include <iostream>
using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int d[n];

    for (int i = 0; i < n; i++)
    {
        d[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && i > j)
            {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {

        if (max < d[i])
            max = d[i];
    }
    cout << max;
}
// d[n] = max(a[j]+1);

// ���� �� �����ϴ� �κ� ������ ���� = d[n];

// �� �� ... �� �� �� = n��
//            j    i
//     <       �̷��� 1
//     >       �̷��� 0
// n-1     n

// ���� n=2 ���,
// 1��°�� 2��°�� ���ؼ� d[n]�� ���� �ְ� �ִ밪(���� �� ������) ����

// n=3 �̸�,
// �� ���� �ѹ� �ϰ�, 3�� 3�� ��ĭ ���� 2�� ���ؼ� �ִ밪 d[n]�� ����