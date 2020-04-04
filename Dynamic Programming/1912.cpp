#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], d[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        d[i] = a[i];
        if (i == 0)
            continue;
        if (d[i] < d[i - 1] + a[i])
            d[i] = d[i - 1] + a[i];

        // int sum = 0;
        // for (int j = i+1; j < n - 1; j++)
        // {
        //     sum += a[j];
        //     if (d[i] < sum)
        //         d[i] = sum;

        // }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << d[i] << " ";
    // }
    // cout << "\n";

    int result = d[0];
    for (int i = 1; i < n; i++)
    {
        if (result < d[i])
            result = d[i];
    }
    cout << result;
}