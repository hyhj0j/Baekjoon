// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWVl47b6DGMDFAXm&categoryId=AWVl47b6DGMDFAXm&categoryType=CODE#none

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    int n = t;

    vector<int> result;

    while (n > 0)
    {
        vector<int> lazer;
        vector<pair<int, int>> stick; //left, right ��ġ
        string input;
        cin >> input;
        int total = 0;
        bool isChecked[input.size()] = {false};
        for (int i = 1; i < input.size(); i++)
        { // ã��
            if (input[i] == ')' && input[i - 1] == '(')
            { // ������ ã��
                lazer.push_back(i);
                isChecked[i] = true;
                isChecked[i - 1] = true;
            }
            else if (input[i] == ')')
            { // �踷�� ã��
                for (int j = i - 1; j >= 0; j--)
                {
                    if (!isChecked[j] && input[j] == '(')
                    {
                        isChecked[j] = true;
                        stick.push_back({j, i});
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < stick.size(); i++)
        {
            for (int j = stick[i].first; j <= stick[i].second; j++)
            {
                for (int k = 0; k < lazer.size(); k++)
                {
                    if (j == lazer[k])
                        total++;
                }
            }
        }
        result.push_back(total + stick.size());

        n--;
    }

    for (int i = 0; i < t; i++)
        cout << "#" << i + 1 << " " << result[i] << "\n";

    return 0;
}

/* Ǯ�� ���� ����
    1. right ) �긦 ���� ã��, ��� ���� ����� left ( �� ã��
        1-1. ���� right �ٷ� ������ right�� �ִ�? �װ� ��������
            - ���Ϳ� �������� right ��ġ�� ��������
        1-2. �ٷ� ������ ���� �ʴ�? �װ� �踷����
            - pair�� ���� ���Ϳ� �踷�� ���۰� ���� ��������
    2. �踷�� ���� �ȿ� ����������(2) right�� � ����ֳ� Ȯ��
        - Ȯ���� ����������+1 �� �߶��� �踷�� ����




        ...............�Ф� ����� �� �� �����µ�...
        �ð��ʰ�..........��...............
        ���۸��ؼ� �ٸ� ����� �ַ�Ǻ���...... �ʹ� �����ϴ�...
        ����...
*/

/*
    * ���� * 
    �ڱ⺸�� �� ���� ������ ���� �� �ִ�
    �׷��� ��ģ ������� �糡���� ��ġ�� ����
    �������� ��� �ϳ� ����
    �׷��� �������� � ������ �糡������ ��ġ�� ����
    () => ������
    �踷�� ���� �� = '(', ������ �� = ')'
*/