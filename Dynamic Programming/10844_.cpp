#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long d[101][10];

    for (int i = 1; i <= 9; i++)
        d[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            d[i][j] = 0;
            if (j - 1 >= 0) //j가 0일때 예외
                d[i][j] += d[i - 1][j - 1];
            if (j + 1 <= 9) //j가 9일때 예외
                d[i][j] += d[i - 1][j + 1];
            d[i][j] %= 1000000000;
        }
    }

    long long result = 0;
    for (int i = 0; i <= 9; i++)
        result += d[n][i];
    result %= 1000000000;
    cout << result;
}