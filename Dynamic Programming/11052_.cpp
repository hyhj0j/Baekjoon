// 카드 구매하기 1 (https://www.acmicpc.net/problem/11052)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; //구매하려는 카드의 수 & 제공되는 카드팩의 수
    cin >> n;
    vector<int> p(n + 1);
    // vector는 생성시 0으로 초기값 설정되어있음. p(n) : 0으로 초기화된 n개의 벡터란 뜻
    // ★★★ vector<int> p(n)와 vector<int> p[n]의 차이 알아보기
    //       => 2차원 벡터 사용시 p[n][n]로 쓰는것만 알겠음 ㅠㅠ
    vector<int> d(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            d[i] = max(d[i], d[i - j] + p[j]);
        }
    }

    cout << d[n];

    //[팩 팩 .... 팩](N-K개) [팩](k개) = 카드 N개
    //d[n] = 카드 n개를 구매하는 비용의 최대값
    //d[n] = max(d[n-i]+ p[i]);
}

// p[i]=k : i개에 k원이란 뜻
// 최대 많은 비용을 지불하는 경우의 '비용'을 출력하라