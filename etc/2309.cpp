// �ϰ� ������ ( https://www.acmicpc.net/problem/2309 )

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int nine = 9;
    int nan[nine];
    int total = 0;
    bool exit = false;
    for (int i = 0; i < nine; i++)
    {
        cin >> nan[i];
        total += nan[i];
    }

    for (int i = 0; i < nine - 1; i++)
    {
        for (int j = i + 1; j < nine; j++)
        {
            if (total - nan[i] - nan[j] == 100)
            {
                nan[i] = -1;
                nan[j] = -1;
                exit = true;
                break;
            }
        }
        if (exit)
            break;
    }

    sort(nan, nan + nine);

    for (int i = 2; i < nine; i++)
        cout << nan[i] << "\n";
}

// �θ��� ��� ��ü�տ��� �� �׸��� �װ� 100�̸� �θ� �� �ֵ��� ������