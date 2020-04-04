// ī�� �����ϱ� 1 (https://www.acmicpc.net/problem/11052)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; //�����Ϸ��� ī���� �� & �����Ǵ� ī������ ��
    cin >> n;
    vector<int> p(n + 1);
    // vector�� ������ 0���� �ʱⰪ �����Ǿ�����. p(n) : 0���� �ʱ�ȭ�� n���� ���Ͷ� ��
    // �ڡڡ� vector<int> p(n)�� vector<int> p[n]�� ���� �˾ƺ���
    //       => 2���� ���� ���� p[n][n]�� ���°͸� �˰��� �Ф�
    vector<int> d(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            d[i] = max(d[i], d[i - j] + p[j]);
        }
    }

    cout << d[n];

    //[�� �� .... ��](N-K��) [��](k��) = ī�� N��
    //d[n] = ī�� n���� �����ϴ� ����� �ִ밪
    //d[n] = max(d[n-i]+ p[i]);
}

// p[i]=k : i���� k���̶� ��
// �ִ� ���� ����� �����ϴ� ����� '���'�� ����϶�