#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n;
vector<int> node[3001];
int check[3001]; // ����Ŭ üũ
int visit[3001]; // �Ÿ� üũ�ϴ� dist ����
int cycle;
bool cycling = false;
int startpoint = 0;

void bfs(int start) // ����Ŭ�������� ����� �Ÿ� ���ϱ�
{
    queue<int> q;
    q.push(start);
    visit[start] = 0; // �湮�ϸ� 0
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < node[x].size(); i++)
        {
            int y = node[x][i];
            if (visit[y] == -1) // �湮 ���ϸ� ����
            {
                q.push(y);
                visit[y] = 0;
                if (check[y] != cycle)
                {
                    visit[y] = visit[x] + 1;
                }
            }
        }
    }
}

int dfs(int x, int pre) // ����Ŭ ���ϱ�
{
    if (check[x] == -1)
    { // -1 : �湮O, -2 : �湮O����ŬX
        startpoint = x;
        return x;
    }
    check[x] = -1;
    for (int i = 0; i < node[x].size(); i++)
    {
        int next = node[x][i]; // y�� x�� next����
        if (next != pre)
        {
            // visit[y] = -1;
            check[next] = dfs(next, x);
        }
        if (check[next] != -1 && check[next] != -2)
        {
            if (x != startpoint)
                return startpoint;
            else
                return -2;
        }
    }
    return -2; // -2 :  ����Ŭ�� ���� ��尡 �ƴ϶� ��
}
// üũ��尡 �̹� -1�� -2�� �ƴ� ���¸�

int main()
{
    fill_n(visit, 3001, -1); // visit �迭 -1�� �ʱ�ȭ, -1 : �湮X , 0 : �湮:O
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (check[i] > 0)
        {
            cycle = check[i];
            break;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "check[" << i << "] :" << check[i] << "\n";
    }

    bfs(1);

    for (int i = 1; i <= n; i++)
    {
        if (visit[i] < 0)
            cout << 0 << " ";
        else
            cout << visit[i]
                 << " ";
    }
}