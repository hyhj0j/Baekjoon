#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, x, a, b, tmp;

    cin >> N;
    //vector<int> v(N);
    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    cin >> x;
    v.erase(v.begin() + (x - 1));

    cin >> a >> b;
    v.erase(v.begin() + (a - 1), v.begin() + b - 1);

    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}