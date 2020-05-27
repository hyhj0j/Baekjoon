// ž ( https://programmers.co.kr/learn/courses/30/lessons/42588 )

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
    {   // hsize ��ŭ�� ť�� ���� ���̸�, �� ť�� ����� 1�� ������
        // why? heights ���� �ں��� �۽�ž�� ã���� ���̱� ������,
        //      �۽�ž�� ã�� ���� ���� ���� �����ϴ� ��..
        queue<int> q;
        int temp = 0;
        for (int i = 0; i < hsize; i++)
            q.push(heights[i]); // ť�� ������� while�� �������� �۾���
        for (int i = 1; i < hsize; i++)
        {
            if (q.front() > q.back())
            { //�ǵڰ� �ٷ� ������ ó���� ���� ���ؼ� ���� ���ʿ� �ִ� ���� ã��
                temp = i;
            }
            q.pop();
        }
        s.push(temp); //�ٷ� answer�� �ƴ϶� stack�� �ִ� ���� : �ڿ������� ���� ���ϰ� �ֱ� ������
                      // stack���� ����ؾ� �������� ���ϴ� ������ ����
        hsize--;
    }

    for (int i = 0; i < heights.size(); i++)
    {   //stack�� �ִ� ���� answer�� �־ �ٸ� ������ ���
        //��� ������ �ٲٸ� ���� �̷��� ���ص�-������..��
        answer.push_back(s.top());
        s.pop();
    }

    return answer;
}