#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    char num; // ���� �ϳ��� "���� ����" �Է¹ޱ� ���� char ���
    cin >> n;
    while (n)
    {
        cin >> num;
        sum += (num - '0'); // num�� char���̱� ������ �׳� ���ϸ� �ƽ�Ű������ ������
                            // ex) '1' - '0' = 49 - 48 = 1
                            //     '2' - '0' = 50 - 48 = 2 ������ �̷����� �Ǿ����
        n--;
    }
    cout << sum;
}