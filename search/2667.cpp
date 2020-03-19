//a¹Ì¿Ï
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 25 + 1;
vector<int> node[MAX + 1];
int visited[MAX][MAX] = {false};
int arr[MAX][MAX];
int cnt = 0;

void dfs(int x, int y)
{
    cnt++;
    visited[x][y] = true;
    for (int i = 0; i < arr[x][y]; i++)
    {
        int x = node[x][i];

        if (!visited[x])
        {
            if (x == 1)
                dfs(x);
        }
    }
}

int main()
{
    int mapSize;
    cin >> mapSize;
    for (int i = 0; i <= mapSize; i++)
        for (int j = 0; j <= mapSize; j++)
        {
            cin >> arr[i][j];
        }
    for (int i = 0; i <= mapSize; i++)
        for (int j = 0; j <= mapSize; j++)
        {
            if (arr[i][j] == 1 && visited[i][j] == false)
            {
                dfs(i, j);
            }
        }
}