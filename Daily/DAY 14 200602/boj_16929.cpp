#include <iostream>

using namespace std;

char map[50][50];
bool check[50][50];
int n, m;
int dirX[4] = {-1, 1, 0, 0};
int dirY[4] = {0, 0, 1, -1};

bool dfs(int x, int y, int preX, int preY)
{
    if (check[x][y])
    {
        return true;
    }
    check[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];
        if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m)
        { // is in map
            if (!(nextX == preX && nextY == preY))
            { // next is not pre
                if (map[x][y] == map[nextX][nextY])
                { // same color
                    if (dfs(nextX, nextY, x, y))
                        return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> map[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check[i][j])
                continue;
            bool cicle = dfs(i, j, -1, -1);
            if (cicle)
            {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
    return 0;
}