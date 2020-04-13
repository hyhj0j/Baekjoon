// ���� ���� ( https://www.acmicpc.net/problem/3085 )

#include <iostream>
#include <vector>

using namespace std;

int check(vector<string> &color)
{
    int n = color.size();
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        for (int j = 1; j < n; j++)
        { // ���� ī��Ʈ
            if (color[i][j] == color[i][j - 1])
            {
                cnt += 1;
            }
            else
            {
                cnt = 1;
            }
            if (ans < cnt)
                ans = cnt;
        }
        cnt = 1;
        for (int j = 1; j < n; j++)
        { // ���� ī��Ʈ
            if (color[j][i] == color[j - 1][i])
            {
                cnt += 1;
            }
            else
            {
                cnt = 1;
            }
            if (ans < cnt)
                ans = cnt;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> color(n);
    for (int i = 0; i < n; i++)
        cin >> color[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j + 1 < n)
            {
                swap(color[i][j], color[i][j + 1]);
                int temp = check(color); // �̶� �ִ� ���� ��
                if (ans < temp)
                    ans = temp;
                swap(color[i][j], color[i][j + 1]);
            }
            if (i + 1 < n)
            {
                swap(color[i][j], color[i + 1][j]);
                int temp = check(color); // �̶� �ִ� ���� ��
                if (ans < temp)
                    ans = temp;
                swap(color[i][j], color[i + 1][j]);
            }
        }
    }
    cout << ans << '/n';
}