//�̷�Ž�� (https://www.acmicpc.net/problem/2178)

// ����
// N��Mũ���� �迭�� ǥ���Ǵ� �̷ΰ� �ִ�.

// 1	0	1	1	1	1
// 1	0	1	0	1	0
// 1	0	1	0	1	1
// 1	1	1	0	1	1
// �̷ο��� 1�� �̵��� �� �ִ� ĭ�� ��Ÿ����, 0�� �̵��� �� ���� ĭ�� ��Ÿ����. �̷��� �̷ΰ� �־����� ��, (1, 1)���� ����Ͽ� (N, M)�� ��ġ�� �̵��� �� ������ �ϴ� �ּ��� ĭ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. �� ĭ���� �ٸ� ĭ���� �̵��� ��, ���� ������ ĭ���θ� �̵��� �� �ִ�.

// ���� �������� 15ĭ�� ������ (N, M)�� ��ġ�� �̵��� �� �ִ�. ĭ�� �� ������ ���� ��ġ�� ���� ��ġ�� �����Ѵ�.

// �Է�
// ù° �ٿ� �� ���� N, M(2 �� N, M �� 100)�� �־�����. ���� N���� �ٿ��� M���� ������ �̷ΰ� �־�����. ������ ������ �پ �Է����� �־�����.

// ���
// ù° �ٿ� ������ �ϴ� �ּ��� ĭ ���� ����Ѵ�. �׻� ������ġ�� �̵��� �� �ִ� ��츸 �Է����� �־�����.

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int const MAX = 100;
int visited[MAX][MAX];
int map[MAX][MAX];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // ��,��,��,��
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
        cin >> matrix_row[i]; // int b; scanf("%1d", &b);�� ������ string.at()�ؼ� ������ �ʿ� ����!
        for (int j = 0; j < m; j++)
        {
            map[i][j] = matrix_row[i].at(j) - '0';
        }
    }
    //�湮X & MAP[I][J]=1�϶� ���µ�
    //MAP[I][J]==MAP[N][M]�̸� ������
    cout << "������ �����ϸ鼭 ���������� �����Ҷ�, ���� �ּ����� ��� : " << bfs(n, m) << "\n";
    cout << "bfs�� ���ư� Ƚ�� : " << cnt << "\n";

    cout << "visited ����� ��� :\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << visited[i][j];
        cout << "\n";
    }
}