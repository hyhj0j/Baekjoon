#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices)
{
    stack<int> s;
    int x;
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = 0; j < prices.size(); j++)
        {
            s.push(prices[j]);
            if (i == j)
            {
                x = s.top();
            }
        }
        int cnt = 0;
        for (int k = i + 1; k < prices.size(); k++)
        {
            int y = s.top();
            s.pop();
            cnt++;
            if (x > y)
                cnt--;
        }
        answer.push_back(cnt);

        while (!s.empty())
            s.pop();
    }

    return answer;
}

int main()
{
    vector<int> v = {1, 2, 3, 2, 3}; // answer={4,3,1,1,0}
    // test2={5,4} answer={0,0}
    // test3={5,5} answer={1,0}
    // test4={7,2,5,4,9,6} answer={1,4,2,2,0,0}
    vector<int> sol = solution(v);
    for (int i = 0; i < sol.size(); i++)
        cout << sol[i];
}

// �ϴ� ���ÿ� ��(5��) �ֱ�
// ������, ù��° �� ����صα� (x������ ����)
// ���ÿ��� 4�� ���� => �Ѱ��� ���鼭 �� ���� ī��Ʈ o
//                  => x ������ ũ�� ���ؼ� x���� ��� ���� ������, �� ���� ī��Ʈ x
//                  => ī��Ʈ �� ������ ���� ���Ϳ� ����
// ���� ��ü ����

// ���� ���ÿ� ��(5��) �ֱ�
// ������, �ι�° �� ����صα�
// ���ÿ��� 3�� ���� ...�ݺ�