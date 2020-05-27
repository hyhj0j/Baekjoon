// 서울에서 김서방 찾기 ( https://programmers.co.kr/learn/courses/30/lessons/12919 )

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul)
{
    string answer = "";
    for (int i = 0; i < seoul.size(); i++)
    {
        if (seoul[i] == "Kim")
        {
            answer = "김서방은 ";
            answer += to_string(i);
            answer += "에 있다";
        }
    }
    return answer;
}