// �似Ǫ�� ���� (https://www.acmicpc.net/problem/1158)

// ����
// �似Ǫ�� ������ ������ ����.

// 1������ N������ N���� ����� ���� �̷�鼭 �ɾ��ְ�, ���� ���� K(�� N)�� �־�����. ���� ������� K��° ����� �����Ѵ�. �� ����� ���ŵǸ� ���� ������ �̷���� ���� ���� �� ������ ����� ������. �� ������ N���� ����� ��� ���ŵ� ������ ��ӵȴ�. ������ ������� ���ŵǴ� ������ (N, K)-�似Ǫ�� �����̶�� �Ѵ�. ���� ��� (7, 3)-�似Ǫ�� ������ <3, 6, 2, 7, 5, 1, 4>�̴�.

// N�� K�� �־����� (N, K)-�似Ǫ�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

// �Է�
// ù° �ٿ� N�� K�� �� ĭ�� ���̿� �ΰ� ������� �־�����. (1 �� K �� N �� 5,000)

// ���
// ������ ���� �似Ǫ�� ������ ����Ѵ�.

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    queue<int> q, result;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        for (int i = 0; i < k - 1; i++)
        {
            int x = q.front();
            q.push(x);
            q.pop();
        }
        result.push(q.front());
        q.pop();
    }
    cout << "<";
    while (!result.empty())
    {
        if (result.size() == 1)
        {
            cout << result.front() << ">";
        }
        else
        {
            cout << result.front() << ", ";
        }
        result.pop();
    }
}