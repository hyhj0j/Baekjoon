// 탑 ( https://programmers.co.kr/learn/courses/30/lessons/42588 )

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights)
{
    vector<int> answer;
    stack<int> s;
    int hsize = heights.size();

    while (hsize > 0)
    {   // hsize 만큼의 큐를 만들 것이며, 이 큐는 사이즈가 1씩 감소함
        // why? heights 벡터 뒤부터 송신탑을 찾아줄 것이기 때문에,
        //      송신탑을 찾은 가장 뒤의 값은 삭제하는 식..
        queue<int> q;
        int temp = 0;
        for (int i = 0; i < hsize; i++)
            q.push(heights[i]); // 큐의 사이즈는 while을 돌때마다 작아짐
        for (int i = 1; i < hsize; i++)
        {
            if (q.front() > q.back())
            { //맨뒤값 바로 전까지 처음과 끝값 비교해서 가장 왼쪽에 있는 값을 찾음
                temp = i;
            }
            q.pop();
        }
        s.push(temp); //바로 answer이 아니라 stack에 넣는 이유 : 뒤에서부터 값을 구하고 있기 때문에
                      // stack으로 출력해야 문제에서 원하는 순서로 나옴
        hsize--;
    }

    for (int i = 0; i < heights.size(); i++)
    {   //stack에 있는 값을 answer로 넣어서 바른 순서로 출력
        //사실 리턴을 바꾸면 굳이 이렇게 안해도-되지만..ㅎ
        answer.push_back(s.top());
        s.pop();
    }

    return answer;
}