#include <iostream>
using namespace std;
int main()
{
    int n, i, j, k, l;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i + 1; j++)
            cout << "*";
        for (k = 0; k < (2 * n) - (2 * i) - 2; k++)
            cout << " ";
        for (l = 0; l < i + 1; l++)
            cout << "*";
        cout << "\n";
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
            cout << "*";
        for (k = 0; k < (2 * i) + 2; k++)
            cout << " ";
        for (l = 0; l < n - i - 1; l++)
            cout << "*";
        cout << "\n";
    }
}