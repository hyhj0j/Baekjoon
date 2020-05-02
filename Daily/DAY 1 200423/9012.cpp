// https://www.acmicpc.net/problem/9012

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    string brakets;
    int left = 0, right = 0;
    while (t > 0)
    {
        cin >> brakets;
        for (int i = 0; i < brakets.size(); i++)
        {
            if (')' == brakets[i])
                right++;
            else
                left++;
            if (left < right)
                break;
        }
        if (left == right)
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
        left = 0, right = 0;
        t--;
    }
}