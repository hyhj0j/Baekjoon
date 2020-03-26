#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int m, n, h;
    cin >> m >> n >> h;
    int box[h * m][h * n];

    for (int k = 0; k < h; k++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                scanf("%d", &box[j][i]);
            }
        }
    }

    cout << endl;

    for (int k = 0; k < h; k++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                printf("%d", box[j][i]);
            }
            printf("\n");
        }
    }
}