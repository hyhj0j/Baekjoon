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

// 일단 스택에 값(5개) 넣기
// 넣을때, 첫번째 값 기억해두기 (x변수에 저장)
// 스택에서 4개 빼기 => 한개씩 빼면서 팝 갯수 카운트 o
//                  => x 변수랑 크기 비교해서 x보다 방금 뺀게 작으면, 팝 갯수 카운트 x
//                  => 카운트 한 값들은 따로 벡터에 저장
// 스택 전체 비우기

// 다음 스택에 값(5개) 넣기
// 넣을때, 두번째 값 기억해두기
// 스택에서 3개 빼기 ...반복