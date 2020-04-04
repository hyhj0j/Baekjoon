// 카드 구매하기 2 (https://www.acmicpc.net/problem/16194)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n + 1, 10000);
    vector<int> d(n + 1, 10000);

    for (int i = 1; i <= n; i++)
        cin >> p[i];

    p[0] = d[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            d[i] = min(d[i], d[i - j] + p[j]);
        }
    }
    cout << d[n];
}