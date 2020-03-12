//DFS와 BFS

// 문제
// 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

// 입력
// 첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

// 출력
// 첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

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
        node[b].push_back(a); //push_back하여 2차원 배열이 됨 & 노드가 양방향으로 연결되어 있음
    }
    for (int i = 1; i <= n; i++) // node가 사용하는 배열들만 정렬
    {
        sort(node[i].begin(), node[i].end());
    }
    dfs(v);
    memset(visit, false, sizeof(visit)); // dfs 후 메모리초기화하여 탐색 전 원 상태에서 bfs 작동
    printf("\n");
    bfs(v);
}