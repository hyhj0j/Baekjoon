#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int check[20001];
vector<int> node[20001];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    int chk = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if (check[x] == 1)
            chk = 2;
        else if (check[x] == 2)
            chk = 1;

        for (int i = 0; i < node[x].size(); i++)
        {
            int y = node[x][i];
            if (check[y] == 0)
            {
                q.push(y);
                check[y] = chk;
            }
        }
    }
}

int main()
{
    int k, v, e;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> v >> e;

        for (int j = 1; j <= v; j++)
        {
            node[j].clear();
            check[j] = 0;
        }
        for (int j = 0; j < e; j++)
        {
            int a, b;
            cin >> a >> b;
            node[a].push_back(b);
            node[b].push_back(a);
        }
        for (int j = 1; j <= v; j++)
        {
            if (check[j] == 0)
                bfs(j);
        }
        bool isB = true;
        for (int ii = 1; ii <= v; ii++)
        {
            for (int jj = 0; jj < node[ii].size(); jj++)
            {
                int kk = node[ii][jj];
                if (check[ii] == check[kk])
                    isB = false;
            }
        }

        if (isB)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}