#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cin이 scanf보다 3배쯤 느리기 때문에
    //위 두줄을 추가하여 cin의 속도를 높여줌

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\n"; // endl보다 \n이 속도가 빠름
    }
}

//이렇게 코딩했더니 시간초과
//
//
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     for(int i=0; i<n ;i++){
//         cout << i+1 << endl;
//     }
// }