#include <iostream>

using namespace std;
int d[100001];
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        d[i] = i;
        for (int j = 1; j * j <= i; j++)
        {
            if (d[i] > d[i - j * j] + 1)
                d[i] = d[i - j * j] + 1;
        }
    }

    cout << d[n];
}

// n=1 -> 1力蚌 1俺
// n=2 -> 1力蚌 2俺
// n=3 -> 1力蚌 3俺
// n=4 -> 1力蚌 4俺 or 2力蚌 1俺
// n=5 -> 1力蚌 5俺 or 2力蚌 1俺 1力蚌 1俺
// n=6 -> 1力蚌 6俺 or 2力蚌 1俺 1力蚌 2俺
// n=7 -> 1力蚌 7俺 or 2力蚌 1俺 1力蚌 3俺
// n=8 -> 1力蚌 8俺 or 2力蚌 1俺 1力蚌 4俺 or 2力蚌 2俺
// n=9 -> 1力蚌 9俺 or 2力蚌 1俺 1力蚌 5俺 or 2力蚌 2俺 1力蚌 1俺 or 3力蚌 1俺

// *风飘 竞匡 荐 乐绰 局甸篮 弥家蔼 = 1俺

// け力蚌 + け力蚌 + ... + け力蚌 = n
//          i             j