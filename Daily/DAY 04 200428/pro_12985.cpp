// 예상 대진표 ( https://programmers.co.kr/learn/courses/30/lessons/12985 )

#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer;
    int temp = 2;
    int round = 1;
    while (1)
    {
        if (n == temp)
        {
            break;
        }
        temp *= 2;
        round++;
    }
    int cnt = 1;
    // 무조건 a-b는 1-2 / 3-4 / 5-6 이런식이어야됨
    while (cnt <= round)
    {
        if (a - b == 1 && a % 2 == 0 && b % 2 == 1)
        { // 만난 경우
            break;
        }
        else if (b - a == 1 && b % 2 == 0 && a % 2 == 1)
        { // 만난 경우
            break;
        }
        else
        { // 아직 안 만난 경우
            if (a % 2 == 0)
                a /= 2;
            else
                a = (a + 1) / 2;
            if (b % 2 == 0)
                b /= 2;
            else
                b = (b + 1) / 2;
        }
        cnt++;
    }
    answer = cnt;
    return answer;
}