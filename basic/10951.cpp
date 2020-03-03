#include <iostream>
using namespace std;
int main()
{
    int a, b;
    while (cin >> a >> b) // 조건에 입력이 들어가도 되는거 처음 알았음
                          // C VERSION : scanf("%d %d", &a, &b) != EOF
                          // 테스트 케이스 수 or 종료 조건 없을땐, 파일 끝(End of File,EOF) 사용
    {
        cout << a + b << endl;
    }
}