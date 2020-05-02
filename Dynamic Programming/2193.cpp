// ��ģ�� (https://www.acmicpc.net/problem/2193)

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long d[n][2];
    d[1][0] = 0;
    d[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {

        d[i][0] = d[i - 1][1] + d[i - 1][0];
        d[i][1] = d[i - 1][0];
    }

    cout << d[n][0] + d[n][1];
}

// 1. ���� 11 �Ұ�
// 2. ù�ڸ� 0 �Ұ�
// d[1][0] = 0;
// d[1][1] = 1;
// d[2][0] = 1;
// d[2][1] = 0;

// [1] = 1, [2] = 0 ������!
// [3] = n
// n-1 == 0 �̸� 0 �Ǵ� 1
// n-1 == 1 �̸� 0
// 1  0  1  0
// 1  0  0  0
// ��  ��  �� ... �� = n��
// (n-1        )( 1)

// d[n][l] = n�ڸ� ��ģ�� �������� l

// d[n][0] = d[n-1][1] + d[n-1][0];
// d[n][1] = d[n-1][0];
//  1    0
// n-1 n