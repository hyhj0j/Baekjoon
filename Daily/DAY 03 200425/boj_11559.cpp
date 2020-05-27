// Puyo Puyo ( https://www.acmicpc.net/problem/11559 ) 골드5
// 너무 어려워서............. 다시 꼭 풀어봐야함

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 상 하 우 좌
string map[12];

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int bfs(void)
{
    queue<pair<int, int>> q;
    int cnt = 0;
    while (1)
    {
        vector<pair<int, int>> v; // 부실 블럭 위치 저장
        bool visited[12][6] = {false};
        for (int y = 11; y >= 0; y--)
        {
            for (int x = 0; x < 6; x++)
            {
                if (map[y][x] == '.')
                    continue;
                else
                {
                    queue<pair<int, int>> popped;
                    char color = map[y][x];
                    q.push({y, x});
                    visited[y][x] = true;
                    while (!q.empty())
                    {
                        int cury = q.front().first;
                        int curx = q.front().second;
                        popped.push({cury, curx});
                        q.pop();
                        for (int i = 0; i < 4; i++)
                        {
                            int nexty = cury + moveDir[i].y;
                            int nextx = curx + moveDir[i].x;

                            if (nexty >= 0 && nexty < 12 && nextx >= 0 && nextx < 6)
                                if (!visited[nexty][nextx] && color == map[nexty][nextx])
                                {
                                    q.push({nexty, nextx});
                                    visited[nexty][nextx] = true;
                                }
                        }
                    }

                    if (popped.size() >= 4)
                    {
                        while (!popped.empty())
                        {
                            v.push_back({popped.front().first, popped.front().second});
                            popped.pop();
                        }
                    }
                }
            }
        }
        if (v.size() > 0)
        {
            sort(v.begin(), v.end(), compare); // x기준 오름차순 정렬
            for (int i = 0; i < v.size(); i++)
            {
                for (int j = v[i].first; j > 0; j--)
                    map[j][v[i].second] = map[j - 1][v[i].second];
                map[0][v[i].second] = '.';
            }
            cnt++;
        }
        else
            break;
    }
    return cnt;
}

int main()
{
    for (int i = 0; i < 12; i++)
        cin >> map[i];
    cout << bfs();
    return 0;
}

// 밑에서부터 위로 하나하나 BFS로 확인 : 뭘? => 4개 이상 같은 색이 상하좌우로 연결되어 있는지
// - 동시에 터지면 연쇄 하나 : CNT +1
// 블록을 터뜨림 : 안의 값을 '.'으로 바꿈
// 블록이 터지면 블록들의 위치가 바뀜 : 위의 과정 다시 반복
// 터질게 없으면 끝내고 최대 연쇄값 출력