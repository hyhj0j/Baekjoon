
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {1, 15, 9, -6, 11, -1};
    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());

    // algorithm ���̺귯���� �ִ� �Լ�
    // �տ� ������ (*) ��!!! �ٿ����� �� �׷��� ������
    // *max_element , *min_element

    cout << "max : " << max << " min : " << min;
}