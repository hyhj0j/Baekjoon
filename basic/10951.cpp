#include <iostream>
using namespace std;
int main()
{
    int a, b;
    while (cin >> a >> b) // ���ǿ� �Է��� ���� �Ǵ°� ó�� �˾���
                          // C VERSION : scanf("%d %d", &a, &b) != EOF
                          // �׽�Ʈ ���̽� �� or ���� ���� ������, ���� ��(End of File,EOF) ���
    {
        cout << a + b << endl;
    }
}