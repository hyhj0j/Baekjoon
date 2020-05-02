#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q; // ��, index
    vector<pair<int, int>> print;

    for (int i = 0; i < priorities.size(); i++)
    {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    int size = q.size();
    while (!q.empty())
    {
        int x = q.front().first;
        int xi = q.front().second;
        int y = pq.top();
        if (x < y)
        { //�� ��(x)���� ū ���� ������ �� �� ���� �ڷ� �Ѱ�
            q.pop();
            q.push({x, xi});
        }
        else if (x == y)
        { //�� ���� ���� ū ���� �׳� �μ���
            q.pop();
            pq.pop();
            print.push_back({x, xi});
        }
    }

    /*
    if(priorities[now_index] != *max_element(priorities.begin(),priorities.end()))
        ���Ϳ��� ���� ū �� �ٷ� �������� �Լ�
        *max_element , *min_element
    */
    for (int i = 0; i < size; i++)
    {
        if (print[i].first == priorities[location] && print[i].second == location)
            answer = i + 1;
    }

    return answer;
}

int main()
{
    vector<int> v = {1, 1, 9, 1, 1, 1};
    cout << solution(v, 0);
}