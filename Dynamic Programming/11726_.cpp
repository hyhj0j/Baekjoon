#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int d[n + 1];
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
    }
    cout << d[n] % 10007;
}