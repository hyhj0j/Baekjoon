
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {1, 15, 9, -6, 11, -1};
    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());

    // algorithm 라이브러리에 있는 함수
    // 앞에 포인터 (*) 꼭!!! 붙여야함 안 그러면 오류남
    // *max_element , *min_element

    cout << "max : " << max << " min : " << min;
}