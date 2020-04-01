#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    int d[n];
    d[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        d[i] = d[i - 1] + 1;
        if (i % 2 == 0 && d[i] > d[i / 2] + 1)
            d[i] = d[i / 2] + 1;
        if (i % 3 == 0 && d[i] > d[i / 3] + 1)
            d[i] = d[i / 3] + 1;
    }

    cout << d[n];
}

// d[n] = n을 1로 만드는 최소 연산 횟수
// 1. x%3
// 2. x%2
// 3. x-1
// ======>N을 1로 만들기
// 연산 사용 횟수의 최솟값을 출력하라