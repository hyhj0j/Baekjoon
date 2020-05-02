// APC는 왜 서브태스크 대회가 되었을까? ( https://www.acmicpc.net/problem/17224 )
// (100/140) : SUB1, SUB2 다 돌아가는데 왜 SUB1만 솔 인지 당최 이유 모름;

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)     // 두번째가 같을때
        return a.first < b.first; // 첫번째는 내림이든 오름이든 상관없음 그래서 오름차순<으로함. 내림일땐>이거임.
    return a.second < b.second;   // 두번째는 무조건 오름차순<으로 정렬해야됨
}

int main()
{
    int n, l, k;
    cin >> n >> l >> k;
    pair<int, int> sub[n];
    for (int i = 0; i < n; i++)
    {
        cin >> sub[i].first >> sub[i].second;
    }

    int total = 0;
    int cnt = 0;

    sort(sub, sub + n, compare);

    for (int i = 0; i < n; i++)
    {
        if (sub[i].second <= l)
        {
            total += 140;
            cnt++;
        }
        else if (sub[i].first <= l && sub[i].second > l)
        {
            total += 100;
            cnt++;
        }
        if (cnt >= k)
            break;
    }

    cout << total;
}

// 일단 어려운문제 l 체크해서 먼저 해결
// 어려운 문제 해결했으면 그 문제는 끝난 것 신경쓰지마
// 쉬운문제 l 체크해서 내 l 이하인것 풀어
// 이때 k 수 초과됐나 확인해야돼