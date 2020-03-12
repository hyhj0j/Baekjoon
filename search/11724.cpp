//���� ����� ����

// ����
// ���� ���� �׷����� �־����� ��, ���� ��� (Connected Component)�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

// �Է�
// ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. (1 �� N �� 1,000, 0 �� M �� N��(N-1)/2) ��° �ٺ��� M���� �ٿ� ������ �� ���� u�� v�� �־�����. (1 �� u, v �� N, u �� v) ���� ������ �� ���� �־�����.

// ���
// ù° �ٿ� ���� ����� ������ ����Ѵ�.

#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 10001;
const int MAX_M = (MAX_N * (MAX_N - 1)) / 2;

vector<int> node[MAX_N];
int visited[MAX_N];

void dfs(int);

int main()
{
    int n, m;
    int u, v;
    int cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {

        scanf("%d %d", &u, &v);
        node[u].push_back(v);
        node[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) // ���� ���� �ֳ� Ȯ��
    {
        if (!visited[i]) //false�� ������ visited�� �����ִ� �� = ������ ���� ��
        {
            dfs(i);
            cnt++;
        }
    }
    printf("%d", cnt);
}

void dfs(int start)
{
    if (visited[start])
        return;
    visited[start] = true;
    //printf("%d ", start);

    for (int i = 0; i < node[start].size(); i++)
    {
        int x = node[start][i];
        dfs(x);
    }
}