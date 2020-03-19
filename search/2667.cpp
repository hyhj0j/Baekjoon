// 단지번호붙이기 (https://www.acmicpc.net/problem/2667)

// 문제
// 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

// 입력
// 첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

// 출력
// 첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 25;
int visited[MAX][MAX] = {0};
int map[25][25];
int n, cnt, add = 1;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //상,하,좌,우

bool isInMap(int a, int b)
{
    return (a >= 0 && a < n) && (b >= 0 && b < n);
}

void dfs(int x, int y)
{
    visited[x][y] = add;
    cnt++;
    for (int i = 0; i < sizeof(dir) / sizeof(dir[0]); i++)
    {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if (map[next_x][next_y] == 1 && isInMap(next_x, next_y) && !visited[next_x][next_y])
        {
            dfs(next_x, next_y);
        }
    }
}

int main()
{
    vector<int> result;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &map[i][j]);
        }

    // 1. map[i][j]==1 일때 dfs
    // 2. MATRIX 내부에 있을때 dfs
    // 3. visited[i][j] == false 일때 dfs

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                cnt = 0;
                dfs(i, j);
                result.push_back(cnt); //dfs 돌고 나올때마다 즉, 연결이 끊어질때마다 그 dfs 안에 돌았던 노드 수를 result에 넣음
                add++;                 // visited 숫자를 다르게해서 구역 표시함
            }
        }

    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << visited[i][j];
        }
        cout << endl;
    }

    cout << result.size() << "\n";

    sort(result.begin(), result.end()); //오름차순으로 정렬
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << "\n"; // 각 구역마다 dfs된 노드들의 수 출력
}