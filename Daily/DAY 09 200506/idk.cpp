#include <stdio.h>
typedef unsigned long long ull;

ull t[1001];

int main()
{
    int n, m, k;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int k, a;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
            scanf("%d", &a), t[i] |= ((ull)1 << a);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int p, q, cnt = 0;
        ull tmp = 0;
        scanf("%d", &p);
        for (int j = 0; j < p; j++)
            scanf("%d", &q), tmp |= ((ull)1 << q);
        tmp = ~tmp;
        for (int j = 0; j < n; j++)
            if (!(tmp & t[j]))
                cnt++;
        printf("%d\n", cnt);
    }

    return 0;
}