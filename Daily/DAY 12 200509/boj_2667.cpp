#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int visit[25][25] = {0};
int map[25][25];
int dirX[4] = {0, 0, 1, -1}; // ÁÂ¿ìÇÏ»ó
int dirY[4] = {-1, 1, 0, 0};
int cnt = 0;
//     2,3
// 3,2 3,3 3,4
//     4,3

bool isInMap(int a, int b)
{
    if (0 <= a && a < n && 0 <= b && b < n)
        return true;

    return false;
}

void dfs(int x, int y, int group)
{
    if (visit[x][y] != 0)
        return;
    visit[x][y] = group;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dirX[i], nextY = y + dirY[i];
        if (map[nextX][nextY] != 0 && isInMap(nextX, nextY) && visit[nextX][nextY] == 0)
        {
            dfs(nextX, nextY, group);
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    int group = 0;
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1 && visit[i][j] == 0)
            {
                dfs(i, j, ++group);
                result.push_back(cnt);
                cnt = 0;
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << visit[i][j];
    //     }
    //     cout << "\n";
    // }

    cout << group << endl;
    sort(result.begin(), result.end());
    for (int i = 0; i < group; i++)
        cout << result[i] << endl;
}