#include <iostream>
using namespace std;
int main()
{
    int n, m, k, team;
    cin >> n >> m >> k;

    team = min((n + m - k) / 3, n / 2);
    team = min(team, m);
    cout << team;
}

int min(int a, int b)
{
    int min;
    min = a > b ? b : a;
    return min;
}