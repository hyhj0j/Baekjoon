#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    char ascii = 'a';
    int arr[26];
    fill_n(arr, 26, 0);

    for (int i = 0; i <= 25; i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            int x = s[j];
            if (ascii == x || ascii == x + 32)
            {
                arr[i]++;
            }
        }
        ascii += 1;
    }

    int maxidx = 0, max = arr[0], cnt = 0;

    for (int i = 1; i <= 25; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            maxidx = i;
        }
    }
    for (int i = 0; i <= 25; i++)
    {
        if (max == arr[i])
        {
            cnt++;
        }
    }

    if (cnt == 1)
    {
        printf("%c", 65 + maxidx);
    }
    else
    {
        cout << "?";
    }
}

// 97 = a, 122 = z

// char a = 'a';
// printf("%c ", a - 32);
