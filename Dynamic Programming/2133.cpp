// ##타일 채우기 (♧♧♧♧♧)

// 문제
// 3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

// 입력
// 첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

// 출력
// 첫째 줄에 경우의 수를 출력한다.

#include <iostream>
using namespace std;

int a[31] = {0};

int dp(int n)
{
    if (n == 0)
        return 1;
    if (n == 2)
        return 3;
    if (n % 2 != 0)
        return 0;
    if (a[n] != 0)
        return a[n];
    int result = 3 * dp(n - 2);
    for (int i = 3; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            result += 2 * dp(n - i);
        }
    }

    return a[n] = result;
}

int main()
{
    int n;
    cin >> n;
    cout << dp(n);
    return 0;
}