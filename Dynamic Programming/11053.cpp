// 가장 긴 증가하는 부분 수열 (https://www.acmicpc.net/problem/11053)

#include <iostream>
using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int d[n];

    for (int i = 0; i < n; i++)
    {
        d[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && i > j)
            {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {

        if (max < d[i])
            max = d[i];
    }
    cout << max;
}
// d[n] = max(a[j]+1);

// 가장 긴 증가하는 부분 수열의 길이 = d[n];

// ㅁ ㅁ ... ㅁ ㅁ ㅁ = n개
//            j    i
//     <       이러면 1
//     >       이러면 0
// n-1     n

// 만약 n=2 라면,
// 1번째랑 2번째랑 비교해서 d[n]에 갯수 넣고 최대값(가장 긴 수열값) 츨력

// n=3 이면,
// 위 과정 한번 하고, 3과 3의 한칸 앞인 2를 비교해서 최대값 d[n]에 넣음