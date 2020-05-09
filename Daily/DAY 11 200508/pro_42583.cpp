#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int getSum(queue<pair<int, int>> box)
{
    int sum = 0;
    int size = box.size();
    for (int i = 0; i < size; i++)
    {
        sum += box.front().first;
        box.pop();
    }
    return sum;
}

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int t = 0;
    int size = truck_weights.size();
    queue<int> q;
    for (int i = 0; i < size; i++)
    {
        q.push(truck_weights[i]);
    }

    queue<pair<int, int>> box; // {무게, 처음으로 나간 초}
    while (1)
    {
        t++;
        int x = q.front();
        if (q.empty())
        {
            int boxsize = box.size();
            for (int i = 0; i < boxsize; i++)
            {
                answer = box.front().second;
                box.pop();
            }
            break;
        }
        if (t == box.front().second)
        {
            box.pop();
        }

        if (getSum(box) + x <= weight)
        {
            box.push({x, t + bridge_length});
            q.pop();
        }
        else
        {
            continue;
        }
    }

    return answer;
}

// sum이 브릿지무게보다 적으면, 현재 초에 다음 큐에 있는 애도 다리에 올릴 수 있음
// - 다리에 올리는 것 = v.push 하는 것
// sum이 브릿지무게보다 크면, 다음 초에 다리에 올려야됨
int main()
{

    vector<int> v = {3, 3, 3, 12, 1};
    cout << solution(10, 15, v);
}