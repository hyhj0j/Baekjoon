#include <iostream>
using namespace std;
int main()
{
    int n, num, max = -1000001, min = 1000001;
    cin >> n;
    while (n)
    {
        cin >> num;
        max = max > num ? max : num;
        min = min > num ? num : min;
        n--;
    }
    cout << min << " " << max;
}