#include <iostream>
using namespace std;
int main()
{
    int n, i, j, k, l;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
            cout << " ";
        for (k = 0; k <= 2 * i; k++)
        {
            if (k % 2 == 0)
                cout << "*";
            else
                cout << " ";
        }

        cout << "\n";
    }
}