#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    int sum = a[1];
    int answer;
    for (int i = 2;; i++)
    {
        sum += 6 * (i - 1);
        a.push_back(sum);

        if (a[i] >= n && a[i - 1] < n)
        {
            answer = i;
            break;
        }
        else if (a[i] > n && a[i - 1] <= n)
        {
            answer = i;
            break;
        }
    }
    if (n == 1)
        cout << 1;
    else
        cout << answer;
}
