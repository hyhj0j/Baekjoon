//연결 요소의 개수

// 문제
// 방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

// 출력
// 첫째 줄에 연결 요소의 개수를 출력한다.

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
    for (int i = 1; i <= n; i++) // 끊긴 것이 있나 확인
    {
        if (!visited[i]) //false인 상태의 visited가 남아있단 것 = 연결이 끊긴 것
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