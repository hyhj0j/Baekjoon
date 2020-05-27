#include <iostream>
#include <cstdlib>

using namespace std;

pair<int, int> location[1001];

int time(int a, int b)
{
    return abs(location[a].first - location[b].first) + abs(location[a].second - location[b].second);
}

int main()
{
    int n, t;    //n=���� ��, t=�ڷ���Ʈ�� �ɸ��� �ð�
    int s, x, y; // s=0 Ư������x, s=1 Ư������o, (x,y) : ������ǥ
    int m, a, b; // a,b : a���� b�� ����
    // (x1,y1) -> (x2,y2)�϶�, Ư������ �ƴ϶� �ڷ���Ʈ ���� �� ���� �ð� : abs(x1-x2)+abs(y1-y2);
    cin >> n >> t;
    int special[n + 1];
    int map[n + 1][n + 1];
    for (int i = 0; i < n; i++)
        cin >> special[i + 1] >> location[i + 1].first >> location[i + 1].second;
    cin >> m;
    pair<int, int> go[m];

    for (int i = 0; i < m; i++)
        cin >> go[i].first >> go[i].second;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                map[i][j] = 0;
            else
            {
                map[i][j] = time(i, j);
                if (special[i] == 1 && special[j] == 1 && map[i][j] > t)
                    map[i][j] = t;
            }
        }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                else if (map[i][j] > map[i][k] + map[k][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }

    for (int i = 0; i < m; i++)
    {
        int a = go[i].first;
        int b = go[i].second;

        cout << map[a][b] << "\n";
    }
}

// 1. go�� �ִ� �� ���õ��� �Ѵ� �ڷ���Ʈ �������� üũ
// 1-1. �����ϸ�, �ڷ���Ʈ �ð� ��� -��-
// 1-2. �Ұ����ϸ�, location ��� �� ���