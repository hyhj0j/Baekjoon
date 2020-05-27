#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string c[n];

    for (int i = 0; i < n; i++)
    {
        int k[n];
        cin >> k[i];
        getline(cin, c[i]);
        c[i] += " ";
    }

    int m;
    cin >> m;
    string s[m];

    for (int i = 0; i < m; i++)
    {
        int p[m];
        cin >> p[i];
        getline(cin, s[i]);
        s[i] += " ";
    }

    for (int i = 0; i < m; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            int size = c[j].size();
            for (int start = 0; start + size <= s[i].size(); start++)
            {

                if (!s[i].compare(start, size, c[j]))
                {
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << "\n";
    }
}