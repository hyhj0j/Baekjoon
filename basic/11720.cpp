#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    char num; // 숫자 하나씩 "공백 없이" 입력받기 위해 char 사용
    cin >> n;
    while (n)
    {
        cin >> num;
        sum += (num - '0'); // num이 char형이기 때문에 그냥 더하면 아스키값으로 더해짐
                            // ex) '1' - '0' = 49 - 48 = 1
                            //     '2' - '0' = 50 - 48 = 2 때문에 이런식이 되어야함
        n--;
    }
    cout << sum;
}