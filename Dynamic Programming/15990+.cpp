// 1,2,3 더하기 5 (https://www.acmicpc.net/problem/15990)

// 못풀었음

#include <iostream>

using namespace std;

int plus(int n)
{
    vector<int> d[n][3];
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    d[n] = plus(n - 1) + plus(n - 2);

    return d[n];
}

int main()
{
    int t;
    cin >> t;
    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        plus(n);
    }
}