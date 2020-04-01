#include <iostream>

using namespace std;
int d[11];
int dp(int i)
{
    if (i == 1)
    {
        return d[1] = 1;
    }
    if (i == 2)
    {
        return d[2] = 2;
    }
    if (i == 3)
    {
        return d[3] = 4;
    }
    d[i - 1] = dp(i - 1);
    d[i - 2] = dp(i - 2);
    d[i - 3] = dp(i - 3);
    d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    return d[i];
}

int main()
{
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << dp(n) << "\n";
    }
}