//�̼���� (https://www.acmicpc.net/problem/2644)

// ����
// �츮 ����� ���� Ȥ�� ģô�� ������ ���踦 �̼���� ������ ǥ���ϴ� ��Ư�� ��ȭ�� ������ �ִ�. �̷��� �̼��� ������ ���� ������� ���ȴ�. �⺻������ �θ�� �ڽ� ���̸� 1������ �����ϰ� �̷κ��� ����� ���� �̼��� ����Ѵ�. ���� ��� ���� �ƹ���, �ƹ����� �Ҿƹ����� ���� 1������ ���� �Ҿƹ����� 2���� �ǰ�, �ƹ��� ������� �Ҿƹ����� 1��, ���� �ƹ��� ��������� 3���� �ȴ�.

// ���� ����鿡 ���� �θ� �ڽĵ� ���� ���谡 �־����� ��, �־��� �� ����� �̼��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

// �Է�
// ������� 1, 2, 3, ��, n (1��n��100)�� ���ӵ� ��ȣ�� ���� ǥ�õȴ�. �Է� ������ ù° �ٿ��� ��ü ����� �� n�� �־�����, ��° �ٿ��� �̼��� ����ؾ� �ϴ� ���� �ٸ� �� ����� ��ȣ�� �־�����. �׸��� ��° �ٿ��� �θ� �ڽĵ� ���� ������ ���� m�� �־�����. ��° �ٺ��ʹ� �θ� �ڽİ��� ���踦 ��Ÿ���� �� ��ȣ x,y�� �� �ٿ� ���´�. �̶� �տ� ������ ��ȣ x�� �ڿ� ������ ���� y�� �θ� ��ȣ�� ��Ÿ����.

// �� ����� �θ�� �ִ� �� �� �־�����.

// ���
// �Է¿��� �䱸�� �� ����� �̼��� ��Ÿ���� ������ ����Ѵ�. � ��쿡�� �� ����� ģô ���谡 ���� ���� �̼��� ����� �� ���� ���� �ִ�. �̶����� -1�� ����ؾ� �Ѵ�.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100;
vector<int> node[MAX];
vector<int> box;

int visited[MAX];
int m;
int cnt = 0, here = 0;

int bfs(int start, int target)
{
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == target)
        {
            return visited[x];
        }
        for (int i = 0; i < node[x].size(); i++)
        {
            int y = node[x][i];
            if (!visited[y])
            {
                q.push(y);
                //box.push_back(y);
                visited[y] = visited[x] + 1;
            }
            // }
            // here++;

            // vector<int>::iterator finding;
            // finding = find(box.begin(), box.end(), target);
            // if (finding == box.end())
            // {
            //     here--;
            // }
            // else
            // {
            //     return here;
            // }
            // box.clear();
        }
    }
    return -1;
}

int main()
{
    int n, a, b;
    cin >> n;
    cin >> a >> b;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        node[x].push_back(y);
        node[y].push_back(x);
    }
    cout << bfs(a, b) << "\n";

    for (int i = 0; i < n + 2; i++)
    {
        cout << visited[i] << " ";
    }
    return 0;
}
