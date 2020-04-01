#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int ascii = 97;
    int arr[122 - 97 + 1];
    fill_n(arr, 123 - 97, -1);
    for (int i = 0; i <= 122 - 97; i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            int x = s[j];
            if (ascii == x)
            {
                arr[i] = j;
                break;
            }
        }
        ascii += 1;
    }

    for (int i = 0; i <= 122 - 97; i++)
    {
        printf("%d ", arr[i]);
    }
}

// 97 = a, 122 = z