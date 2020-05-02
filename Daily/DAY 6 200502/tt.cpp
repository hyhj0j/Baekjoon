#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;

    int size = priorities.size();
    for (int i = 0; i < size; i++)
    {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }

    
    while (!q.empty())
    {
        int i = q.front().first;
        int p = q.front().second;
        q.pop();

        //���� ������ �߿䵵�� ���� ���� �߿䵵��� �μ�
        if (p == pq.top())
        {
            pq.pop();
            answer += 1;

            //���� ������ ���� �μ⸦ ��û�� ������
            if (i == location)
            {
                break;
            }
        }
        else
        {
            //�ٽ� ť�� �ִ´�.
            q.push(make_pair(i, p));
        }
    }

    return answer;
}
int main()
{
    vector<int> v = {8, 8, 1, 8};
    cout << solution(v, 2);
}