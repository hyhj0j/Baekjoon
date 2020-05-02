// #include <iostream>
// #include <string>

// using namespace std;

// int main()
// {
//     long long n, k;
//     cin >> n >> k;
//     // for (long long i = 1; i <= n; i++)
//     // {
//     //     str += to_string(i);
//     //     cout << str << "\n
//     //                    ";
//     // }
//     // if (str.size() < m)
//     //     cout << "-1";
//     // else
//     //     cout << str[m - 1];

//     long long total =0, temp=k, numLength=1, numCount=9;
//     while(temp > numLength * numCount){
//         temp = temp - (numLength * numCount);
//         total = total + numCount;
//         numLength++;
//         numCount = numCount * 10;
//     }

//     total = total + ((temp-1)/ (numLength+1));
//     if(total > n) cout << -1;
//     else{}
// }

// // 1234567891011121314151617181920
// // 123456789 1011121314151617181920...979899 100101102...997998999
// //

// 못풀겠어..........................

#include <stdio.h>

int main(void)
{

    long long N, K, calK;
    long long totalnum = 0;
    long long numcount = 9;
    long long numlength = 1;
    long long tenten = 1;
    long long result;

    scanf("%lld %lld", &N, &K);
    calK = K;

    while (calK > numcount * numlength)
    {
        totalnum += numcount;
        calK -= numcount * numlength;
        numcount *= 10;
        numlength++;
    }

    totalnum += (calK - 1) / numlength + 1;

    if (totalnum > N)
        result = -1;
    else
    {
        long long temp = (calK - 1) % numlength + 1;

        for (int i = 0; i < numlength - 1; i++)
            tenten *= 10;

        for (int i = 0; i < temp; i++)
        {
            result = totalnum / tenten;
            totalnum %= tenten;
            tenten /= 10;
        }
    }

    printf("%d\n", result);

    return 0;
}