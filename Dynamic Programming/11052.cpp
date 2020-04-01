#include <iostream>

using namespace std;


int main()
{
    int n;
    cin >> n;
    int p[n+1],d[n+1];

    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    p[0] = 0;
    d[0] = 0;

    for(int k=1; k<n; k++){
        for(int i=1; i<=n; i++)
            d[k] = max(d[k], d[k-i] + p[i]);
    }
}