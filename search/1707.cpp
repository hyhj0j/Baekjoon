#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_V = 20000 + 1;
const int MAX_E = 200000 + 1;
vector<int> node[MAX_V];
int visited[MAX_V]; // 0 : x , 1 , 2
int cnt;
int dfs(int);

int main()
{
    int t, v, e;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int start;
        cin >> v >> e;
        for (int j = 0; j < e; j++)
        {
            int a, b;
            cin >> a >> b;
            node[a].push_back(b);
            node[b].push_back(a);
            if (i == 0)
                start = a;
        }
        //dfs(start);
        cnt = 1;
        if (dfs(start) == 0)
            cout << "NO\n";
        else
            cout << "YES\n";

        node[MAX_V].clear();
        memset(visited, false, sizeof(visited));
    }
    return 0;
}

int dfs(int start)
{
    int ident;

    if (visited[start])
        return 0;
    if (cnt % 2 == 1)
        visited[start] = 1;
    else
        visited[start] = 2;
    cnt++;
    for (int i = 0; i < node[start].size(); i++)
    {
        int x;
        x = node[start][i];
        // cout << "s " << start << " x " << x
        //      << " v[s] " << visited[start] << " v[x] " << visited[x] << "\n";

        dfs(x);

        if (visited[start] == visited[x])
        {
            ident = 0;
        }
        else
        {
            ident = 1;
        }
    }
    return ident;
}