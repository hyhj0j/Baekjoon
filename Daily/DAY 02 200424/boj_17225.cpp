// �������� �������� ( https://www.acmicpc.net/problem/17225 )
// (100/140) : SUB2 ���̽� �� ������� �� ����� SUB1�� Ǯ���� �Ф�

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    int order[n + 1][3]; // order[1][3] ���� ����
    for (int i = 1; i <= n; i++)
    {
        int t, m;
        char c;
        cin >> t >> c >> m;
        if (c == 'B')
            order[i][1] = 0; // �Ķ��̸� 0
        else
            order[i][1] = 1; // �����̸� 1
        order[i][0] = t;
        order[i][2] = m;
    }

    vector<int> blue, red; //���, ����
    int cntblue = 0, cntred = 0;
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        if (order[i][1] == 0)
        {
            cntblue += order[i][2];
            for (int j = 0; j < order[i][2]; j++)
            {
                blue.push_back(k);
                k++;
            }
        }
        else if (order[i][1] == 1)
        {
            cntred += order[i][2];
            for (int j = 0; j < order[i][2]; j++)
            {
                red.push_back(k);
                k++;
            }
        }
    }

    cout << cntblue << "\n";
    for (int i = 0; i < blue.size(); i++)
    {
        cout << blue[i] << " ";
    }
    cout << "\n"
         << cntred << "\n";
    for (int i = 0; i < red.size(); i++)
    {
        cout << red[i] << " ";
    }
}

// ���, ���� ������ ���� �� ī��Ʈ�ؾߵ�
// ī��Ʈ�ɶ� index(=���° �������� ǥ���� ��)�� �迭�� �����ؾߵ� => ������������ ���
// ���ÿ� ���� ���ɽÿ� ��� �켱!
// �ֹ�&���� , �ֹ�&��