#include <iostream>
using namespace std;
int main()
{
    int n, i, j, k;
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        for (j = 0; j <= n - i - 1; j++)
            cout << " ";
        for (k = 0; k < (2 * i) - 1; k++)
            cout << "*";

        cout << endl;
    }
}

//     * 4 1 5
//    *** 3 3 6
//   ***** 2 5 7
//  ******* 1 7 8
// ********* 0 9 9