// ���� ����ǥ ( https://programmers.co.kr/learn/courses/30/lessons/12985 )

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
    // ������ a-b�� 1-2 / 3-4 / 5-6 �̷����̾�ߵ�
    while (cnt <= round)
    {
        if (a - b == 1 && a % 2 == 0 && b % 2 == 1)
        { // ���� ���
            break;
        }
        else if (b - a == 1 && b % 2 == 0 && a % 2 == 1)
        { // ���� ���
            break;
        }
        else
        { // ���� �� ���� ���
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