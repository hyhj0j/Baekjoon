//미로탐색 (https://www.acmicpc.net/problem/2178)

// 문제
// N×M크기의 배열로 표현되는 미로가 있다.

// 1	0	1	1	1	1
// 1	0	1	0	1	0
// 1	0	1	0	1	1
// 1	1	1	0	1	1
// 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

// 위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

// 입력
// 첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

// 출력
// 첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int const MAX = 100;
int visited[MAX][MAX];
int map[MAX][MAX];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상,하,좌,우
int cnt = 0;

bool isInMap(int a, int b, int n, int m)
{
    return ((a >= 0 && b >= 0) && (a < n && b < m));
}

int bfs(int n, int m)
{
    int cur_x = 0, cur_y = 0;
    queue<pair<int, int>> q;
    q.push(pair<int, int>(cur_x, cur_y));
    visited[cur_x][cur_y] = 1;
    cnt++;

    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < sizeof(dir) / sizeof(dir[0]); i++)
        {
            int next_x = cur_x + dir[i][0];
            int next_y = cur_y + dir[i][1];
            if (isInMap(next_x, next_y, n, m) && !visited[next_x][next_y] && map[next_x][next_y] == 1)
            {
                q.push(pair<int, int>(next_x, next_y));
                visited[next_x][next_y] = visited[cur_x][cur_y] + 1;
                cnt++;
            }
        }
    }
    return visited[n - 1][m - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    string matrix_row[n];

    for (int i = 0; i < n; i++)
    {
        cin >> matrix_row[i]; // int b; scanf("%1d", &b);로 받으면 string.at()해서 분할할 필요 없음!
        for (int j = 0; j < m; j++)
        {
            map[i][j] = matrix_row[i].at(j) - '0';
        }
    }
    //방문X & MAP[I][J]=1일때 도는데
    //MAP[I][J]==MAP[N][M]이면 돌지마
    cout << "조건을 만족하면서 목적지까지 도달할때, 가장 최소한의 경로 : " << bfs(n, m) << "\n";
    cout << "bfs가 돌아간 횟수 : " << cnt << "\n";

    cout << "visited 행렬의 모습 :\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << visited[i][j];
        cout << "\n";
    }
}