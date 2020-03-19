#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 100 + 1;
vector<int> node[MAX + 1];
int visited[MAX + 1] = {false};
int cnt = 0;

void dfs(int virus)
{
    visited[virus] = true;

    for (int i = 0; i < node[virus].size(); i++)
    {
        int x = node[virus][i];

        if (!visited[x])
        {
            cnt++;
            dfs(x);
        }
    }
}

int main()
{
    int computers, networks, virus = 1;
    cin >> computers;
    cin >> networks;
    for (int i = 1; i <= networks; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    dfs(virus);
    cout << cnt;
}