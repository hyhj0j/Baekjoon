// 날짜계산 https://www.acmicpc.net/problem/1476

#include <iostream>

using namespace std;

int main()
{
    int ee, ss, mm, e = 1, s = 1, m = 1; //1<=e<=15, 1<=s<=28, 1<=m<=19
    cin >> ee >> ss >> mm;

    int cnt = 1;
    while (ee != e || ss != s || mm != m)
    {
        e++;
        s++;
        m++;
        if (e == 16)
            e = 1;
        if (s == 29)
            s = 1;
        if (m == 20)
            m = 1;
        cnt++;
    }

    cout << cnt;
}