#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n;
vector<int> node[3001];
int check[3001]; // 사이클 체크
int visit[3001]; // 거리 체크하는 dist 역할
int cycle;
bool cycling = false;
int startpoint = 0;

void bfs(int start) // 사이클에서부터 노드의 거리 구하기
{
    queue<int> q;
    q.push(start);
    visit[start] = 0; // 방문하면 0
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < node[x].size(); i++)
        {
            int y = node[x][i];
            if (visit[y] == -1) // 방문 안하면 돌아
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

int dfs(int x, int pre) // 사이클 구하기
{
    if (check[x] == -1)
    { // -1 : 방문O, -2 : 방문O사이클X
        startpoint = x;
        return x;
    }
    check[x] = -1;
    for (int i = 0; i < node[x].size(); i++)
    {
        int next = node[x][i]; // y는 x의 next값임
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
    return -2; // -2 :  사이클에 속한 노드가 아니란 뜻
}
// 체크노드가 이미 -1도 -2도 아닌 상태면

int main()
{
    fill_n(visit, 3001, -1); // visit 배열 -1로 초기화, -1 : 방문X , 0 : 방문:O
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