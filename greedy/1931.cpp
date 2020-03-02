#include <iostream>
using namespace std;
int main()
{
    int n, cnt = 0, start = 0, end = 1;
    cin >> n;
    int meeting[n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> meeting[i][start] >> meeting[i][end];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (meeting[i][end] > meeting[i + 1][start])
        {
            cnt++;
            cout << "ÀÛµ¿";
        }
    }
    cout << cnt;
}