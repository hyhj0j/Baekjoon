#include <iostream>
#include <string> //getline ��� ����
using namespace std;
int main()
{
    string input;
    while (getline(cin, input)) // getline = ���� ������ �� ���� �� �� �Է�
                                // �� (���߰���) ���� ���� ����.
                                // ���Ͱ����� ��
    {
        cout << input << endl;
    }
}