#include <iostream>
using namespace std;
int main()
{
    int n, i, j, k, l;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            for (j = 0; j < n - i - 1; j++)
                cout << " ";
            for (k = 0; k <= i; k++)
            {
                cout << "*";
            }
        }

        else if (i == n - 1)
            for (l = 0; l < (2 * n) - 1; l++)
                cout << "*";

        else
        {
            for (j = 0; j < n - i - 1; j++)
                cout << " ";
            for (k = 0; k <= 2 * i; k++)
            {
                if ((k % (2 * i)) == 0)
                    cout << "*";
                else
                    cout << " ";
            }
        }
        cout << "\n";
    }
}