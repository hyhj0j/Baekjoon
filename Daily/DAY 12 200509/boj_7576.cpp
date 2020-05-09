#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int box[1001][1001];
int visit[1001][1001] = {0};
int n, m;

int dirX[4] = {0, 0, 1, -1};
int dirY[4] = {-1, 1, 0, 0};
queue<pair<int, int>> q;

bool isInMap(int a, int b)
{
    if (0 <= a && a < n && 0 <= b && b < m)
        return true;
    return false;
}

// void dfs(int x, int y)
// {
//     if (visit[x][y] != 0)
//         return;
//     visit[x][y] = 1;
//     cnt++;
//     for (int i = 0; i < 4; i++)
//     {
//         int nextX = x + dirX[i], nextY = y + dirY[i];
//         if (box[nextX][nextY] == 0 && isInMap(nextX, nextY) && visit[nextX][nextY] == 0)
//         {
//             dfs(nextX, nextY);
//         }
//     }
// }

void bfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dirX[i], nextY = y + dirY[i];
        if (box[nextX][nextY] == 0 && isInMap(nextX, nextY) && visit[nextX][nextY] == 0)
        {
            visit[nextX][nextY] = visit[x][y] + 1;
            q.push({nextX, nextY});
        }
    }
}

// 토마토 여러개가 동시에 bfs 진행되어야함
// 익은 토마토를 큐에 넣음
// dfs(q) 느낌으로 함수 만듬

int main()
{
    cin >> m >> n; // m 가로칸의 수 즉 열, n 세로칸의 수 즉 행
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> box[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (box[i][j] == 1)
            {
                q.push({i, j});
                visit[i][j] = 1;
            }
        }
    }

    while (!q.empty())
    {
        bfs(q.front().first, q.front().second);
        q.pop();
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << visit[i][j];
    //     }
    //     cout << "\n";
    // }

    bool isEmpty = false;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visit[i][j] == 0 && box[i][j] != -1)
            {
                isEmpty = true;
            }
            max = visit[i][j] > max ? visit[i][j] : max;
        }
    }

    if (isEmpty)
        cout << -1;
    else
        cout << max - 1;
}