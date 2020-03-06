// ##Ÿ�� ä��� (����������)

// ����
// 3��N ũ���� ���� 2��1, 1��2 ũ���� Ÿ�Ϸ� ä��� ����� ���� ���غ���.

// �Է�
// ù° �ٿ� N(1 �� N �� 30)�� �־�����.

// ���
// ù° �ٿ� ����� ���� ����Ѵ�.

#include <iostream>
using namespace std;

int a[31] = {0};

int dp(int n)
{
    if (n == 0)
        return 1;
    if (n == 2)
        return 3;
    if (n % 2 != 0)
        return 0;
    if (a[n] != 0)
        return a[n];
    int result = 3 * dp(n - 2);
    for (int i = 3; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            result += 2 * dp(n - i);
        }
    }

    return a[n] = result;
}

int main()
{
    int n;
    cin >> n;
    cout << dp(n);
    return 0;
}