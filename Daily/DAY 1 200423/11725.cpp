#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100000;
int parent[MAX + 1] = {0};
vector<int> node[MAX + 1];

void bfs();

int main()
{

    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    parent[1] = -1;
    bfs();

    for (int i = 2; i <= n; i++)
        cout << parent[i] << "\n";
}

void bfs()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < node[1].size(); i++)
    {
        q.push({1, node[1].at(i)});
    }
    while (!q.empty())
    {
        pair<int, int> sub;
        sub = q.front();
        q.pop();
        parent[sub.second] = sub.first;
        for (int i = 0; i < node[sub.second].size(); i++)
        {
            if (parent[node[sub.second].at(i)] == 0)
                q.push({sub.second, node[sub.second].at(i)});
        }
    }
}
// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// const int MAX = 100000;

// vector<int> node[MAX + 1];
// int parent[MAX + 1] = {0};

// void bfs()
// {
//     queue<pair<int, int>> q;
//     for (int i = 0; i < node[1].size(); i++)
//     {
//         q.push({1, node[1].at(i)});
//     }

//     while (q.size())
//     {
//         pair<int, int> sub = q.front();
//         q.pop();

//         parent[sub.second] = sub.first; // �θ� ���� �־���

//         for (int i = 0; i < node[sub.second].size(); i++)
//         {
//             if (parent[node[sub.second].at(i)] == 0)
//             {
//                 q.push({sub.second, node[sub.second].at(i)});
//             }
//         }
//     }
// }

// int main()
// {
//     int n, a, b;
//     cin >> n;
//     for (int i = 0; i < n - 1; i++)
//     {
//         cin >> a >> b;
//         node[a].push_back(b);
//         node[b].push_back(a);
//     }
//     parent[1] = -1; // 1�� ���� �θ���ϱ�, �� �� �θ�� ���� �� -1
//     bfs();

//     for (int i = 2; i <= n; i++)
//     {
//         cout << parent[i] << "\n";
//     }
// }