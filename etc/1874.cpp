// ���� ���� (https://www.acmicpc.net/problem/1874)

// ����
// ���� (stack)�� �⺻���� �ڷᱸ�� �� �ϳ���, ��ǻ�� ���α׷��� �ۼ��� �� ���� �̿�Ǵ� �����̴�. ������ �ڷḦ �ִ� (push) �Ա��� �ڷḦ �̴� (pop) �Ա��� ���� ���� ���߿� �� �ڷᰡ ���� ���� ������ (LIFO, Last in First out) Ư���� ������ �ִ�.

// 1���� n������ ���� ���ÿ� �־��ٰ� �̾� �þ�������ν�, �ϳ��� ������ ���� �� �ִ�. �̶�, ���ÿ� push�ϴ� ������ �ݵ�� ���������� ��Ű���� �Ѵٰ� ����. ������ ������ �־����� �� ������ �̿��� �� ������ ���� �� �ִ��� ������, �ִٸ� � ������ push�� pop ������ �����ؾ� �ϴ����� �˾Ƴ� �� �ִ�. �̸� ����ϴ� ���α׷��� �ۼ��϶�.

// �Է�
// ù �ٿ� n (1 �� n �� 100,000)�� �־�����. ��° �ٺ��� n���� �ٿ��� ������ �̷�� 1�̻� n������ ������ �ϳ��� ������� �־�����. ���� ���� ������ �� �� ������ ���� ����.

// ���
// �Էµ� ������ ����� ���� �ʿ��� ������ �� �ٿ� �� ���� ����Ѵ�. push������ +��, pop ������ -�� ǥ���ϵ��� �Ѵ�. �Ұ����� ��� NO�� ����Ѵ�.

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int num = 0;
    stack<int> box;
    string index;
    while (n > 0)
    {
        int target;
        cin >> target;
        if (target > num)
        {
            while (target > num)
            {
                num++;
                box.push(num);
                index += '+';
            }
            box.pop();
            index += '-';
        }
        else
        {
            bool found = false;
            if (!box.empty())
            {
                int x = box.top();
                box.pop();
                index += '-';
                if (target == x)
                    found = true;
            }
            if (!found)
            {
                cout << "NO\n";
                return 0;
            };
        }
        n--;
    }
    for (int i = 0; i < index.size(); i++)
    {
        cout << index.at(i) << "\n";
    }

    return 0;
}