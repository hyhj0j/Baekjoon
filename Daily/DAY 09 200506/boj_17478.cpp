#include <iostream>

using namespace std;

int n;

void go(int i, string dash)
{
    if (i == n)
    {
        dash += "____";
        cout << dash << "\"����Լ��� ������?\"\n";
        cout << dash << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        cout << dash << "��� �亯�Ͽ���.\n";
        return;
    }
    else
    {
        dash += "____";
        cout << dash << "\"����Լ��� ������?\"\n";
        cout << dash << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
        cout << dash << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
        cout << dash << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    }
    if (i < n)
    {
        go(i + 1, dash);
        cout << dash << "��� �亯�Ͽ���.\n";
    }
}

int main()
{
    cin >> n;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    cout << "\"����Լ��� ������?\"\n";
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���. \n���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    string dash = "";
    go(1, dash);
    cout << "��� �亯�Ͽ���.";
}