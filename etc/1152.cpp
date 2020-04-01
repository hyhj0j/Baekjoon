#include <iostream>

using namespace std;

// int count(string s)
// {
//     int cnt = 0;
//     if (s[0] == ' ' || s[s.length() - 1] == ' ')
//     {
//         cnt--;
//         if (s.length() == 1)
//             return 0;
//     }

//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == ' ')
//         {
//             cnt++;
//         }
//     }
//     return cnt + 1;
// }

int main()
{
    string s;
    int cnt = 0;
    // getline(cin, s);
    // cout << count(s);
    while (cin >> s)
    {
        cnt++;
    }
    cout << cnt;
}