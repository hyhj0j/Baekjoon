// 124 ������ ���� ( https://programmers.co.kr/learn/courses/30/lessons/12899# )

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string dp(string n)
{
    string re = "";
    string last = "";
    string total = "";
    int intN = stoi(n);
    if (n == "1")
        return "1";
    else if (n == "2")
        return "2";
    else if (n == "3")
        return "4";
    else
    {
        // 40/3=13 -> 13/3=4 -> 4/3=1 -> 1
        int temp = intN / 3;
        if (intN % 3 == 0)
            temp = temp - 1;
        re += dp(to_string(temp)); //n=4�϶�, re=1=���ϰ�

        int temp2;

        if (intN % 3 == 0)
            temp2 = 4;
        else if (intN % 3 == 1)
            temp2 = 1;
        else if (intN % 3 == 2)
            temp2 = 2;

        last += (to_string(temp2)); //last=1=��������=1���ڸ���

        total = re + last; // string �����̴ϱ� "1"+"1" = "11"
    }
    return total;
}

string solution(int n)
{
    string answer = "";

    return dp(to_string(n));
}

// ȿ���� �׽�Ʈ �ΰ� ����... ��.....
// �׷��� �����ߴ� ��... ������ ����ϴ� ��..

// ä���� �����մϴ�.
// ��Ȯ��  �׽�Ʈ
// �׽�Ʈ 1 ��	��� (0.02ms, 3.98MB)
// �׽�Ʈ 2 ��	��� (0.01ms, 3.89MB)
// �׽�Ʈ 3 ��	��� (0.01ms, 3.93MB)
// �׽�Ʈ 4 ��	��� (0.02ms, 3.85MB)
// �׽�Ʈ 5 ��	��� (0.02ms, 3.88MB)
// �׽�Ʈ 6 ��	��� (0.02ms, 3.84MB)
// �׽�Ʈ 7 ��	��� (0.03ms, 3.95MB)
// �׽�Ʈ 8 ��	��� (0.01ms, 3.97MB)
// �׽�Ʈ 9 ��	��� (0.01ms, 3.9MB)
// �׽�Ʈ 10 ��	��� (0.02ms, 3.84MB)
// �׽�Ʈ 11 ��	��� (0.02ms, 4MB)
// �׽�Ʈ 12 ��	��� (0.02ms, 3.91MB)
// �׽�Ʈ 13 ��	��� (0.02ms, 4MB)
// �׽�Ʈ 14 ��	��� (0.02ms, 3.89MB)
// ȿ����  �׽�Ʈ
// �׽�Ʈ 1 ��	���� (�ð� �ʰ�)
// �׽�Ʈ 2 ��	���� (�ð� �ʰ�)
// �׽�Ʈ 3 ��	��� (0.02ms, 3.98MB)
// �׽�Ʈ 4 ��	��� (0.02ms, 3.84MB)
// �׽�Ʈ 5 ��	��� (0.02ms, 3.92MB)
// �׽�Ʈ 6 ��	��� (0.02ms, 3.85MB)
// ä�� ���
// ��Ȯ��: 70.0
// ȿ����: 20.0
// �հ�: 90.0 / 100.0