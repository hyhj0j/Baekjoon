#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, p; // n 줄의 수, p 프랫의 수
    cin >> n >> p;

    vector<pair<int, int>> pitch(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pitch[i].first = x;
        pitch[i].second = y;
    }

    //first가 같나 비교
    // - 같으면 second 비교
    //  - first가 같은 애들 중에서 second가 큰 애가 있다? 그러면
    // - 다르면 cnt++
    //second가
}

// 멜로디는 음의 연속이다.
// 음 = 줄에서 해당하는 프랫을 누르고 줄을 튕긴다.

// 프렛을 여러개 누르고 있으면 가장 높은 프렛의 음이 발생. 뭔 개소리야
// =>아.. 한줄에있는 프렛을 한번에 여러개 누르고 있으면,
// 그 누르고 있는 것들 중에서 가장 높은 음을 내는 프렛의 음 하나만 발생한다?
