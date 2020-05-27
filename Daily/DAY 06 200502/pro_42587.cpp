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
    queue<pair<int, int>> q; // 값, index
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
        { //맨 앞(x)보다 큰 수가 있으면 맨 앞 수를 뒤로 넘겨
            q.pop();
            q.push({x, xi});
        }
        else if (x == y)
        { //맨 앞이 제일 큰 수면 그냥 인쇄해
            q.pop();
            pq.pop();
            print.push_back({x, xi});
        }
    }

    /*
    if(priorities[now_index] != *max_element(priorities.begin(),priorities.end()))
        벡터에서 제일 큰 값 바로 가져오는 함수
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