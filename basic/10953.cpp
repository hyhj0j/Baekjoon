#include <iostream>
using namespace std;
int main()
{
    int t, a, b;
    char comma;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> comma >> b;
        cout << a + b << endl;
    }
}