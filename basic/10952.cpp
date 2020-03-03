#include <iostream>
using namespace std;
int main()
{
    int a, b;
    int end = 0;
    while (cin >> a >> b)
    {
        if (a == end && b == end)
            break;
        cout << a + b << endl;
    }
}