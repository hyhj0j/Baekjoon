// ���￡�� �輭�� ã�� ( https://programmers.co.kr/learn/courses/30/lessons/12919 )

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
            answer = "�輭���� ";
            answer += to_string(i);
            answer += "�� �ִ�";
        }
    }
    return answer;
}