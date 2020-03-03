#include <iostream>
#include <string> //getline 사용 위해
using namespace std;
int main()
{
    string input;
    while (getline(cin, input)) // getline = 엔터 나오기 전 까지 한 줄 입력
                                // 즉 (앞중간뒤) 띄어쓰기 포함 가능.
                                // 엔터값만도 들어감
    {
        cout << input << endl;
    }
}