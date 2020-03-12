//DFS�� BFS

// ����
// �׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, �� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. ���� ��ȣ�� 1������ N�������̴�.

// �Է�
// ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V�� �־�����. ���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����. � �� ���� ���̿� ���� ���� ������ ���� �� �ִ�. �Է����� �־����� ������ ������̴�.

// ���
// ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�. V���� �湮�� ���� ������� ����ϸ� �ȴ�.

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 1000 + 1;
int n, m, v;
vector<int> node[MAX];
int visit[MAX];

void dfs(int start)
{
    if (visit[start])
        return;
    visit[start] = true;
    printf("%d ", start);
    for (int i = 0; i < node[start].size(); i++)
    {
        int x = node[start][i];
        dfs(x);
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        printf("%d ", x);
        for (int i = 0; i < node[x].size(); i++)
        {
            int y = node[x][i];
            if (!visit[y])
            {
                q.push(y);
                visit[y] = true;
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &v);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        node[a].push_back(b);
        node[b].push_back(a); //push_back�Ͽ� 2���� �迭�� �� & ��尡 ��������� ����Ǿ� ����
    }
    for (int i = 1; i <= n; i++) // node�� ����ϴ� �迭�鸸 ����
    {
        sort(node[i].begin(), node[i].end());
    }
    dfs(v);
    memset(visit, false, sizeof(visit)); // dfs �� �޸��ʱ�ȭ�Ͽ� Ž�� �� �� ���¿��� bfs �۵�
    printf("\n");
    bfs(v);
}