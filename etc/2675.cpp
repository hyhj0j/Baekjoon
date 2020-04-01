#include <iostream>

using namespace std;

int main()
{
    int t, r, k = 0;
    string s;
    cin >> t;
    while (t > 0)
    {
        cin >> r >> s;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < r; j++)
                cout << s[i];
        }
        cout << "\n";
        t--;
    }
}