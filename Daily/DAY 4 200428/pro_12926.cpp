// 시저 암호 ( https://programmers.co.kr/learn/courses/30/lessons/12926 )

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n)
{
    string answer = "";
    while (n > 0)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                if (s[i] == 'z' || s[i] == 'Z')
                    s[i] = s[i] - 25;
                else
                    s[i] = s[i] + 1;
            }
        }
        n--;
    }
    answer = s;
    return answer;
}