#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

vector<int> prime = {1, 2, 3, 5, 7};
bool str[10];

void fillPrime(int nums)
{
    for (int i = 8; i <= nums; i++)
    {
        if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0)
            prime.push_back(i);
    }
}

void div(int nums, bool str[]) // � ������ ������ Ȯ���ϴ� �Լ�
{
    while (1)
    { // numbers�� �� ���� bool���� true�� ǥ���ϱ�

        int x = nums % 10;
        str[x] = true;
        int y = nums / 10;
        if (1 <= y && y <= 9)
        {
            str[y] = true;
            break;
        }
        nums /= nums;
    }
}

int solution(string numbers)
{
    int answer = 0;
    int cnt = 0;
    int nums = stoi(numbers);
    div(nums, str[10]);

    sort(numbers.begin(), numbers.end(), greater<int>()); // �Ҽ� ���ϱ�
    nums = stoi(numbers);
    fillPrime(nums);

    for (int i = 0; i < prime.size(); i++)
    {
        for (int j = 0; j < prime[i].size(); j++)
        {
        }
    }
    //������0�� string 0���� �ڸ��� �ִ� ���� str == true���� Ȯ��
    //������ ī��Ʈ
    //�ƴϸ� ī��Ʈ ���ϰ� ������0�� string 1��°�� �Ѿ
    //������0�� string ���� ��ŭ �� ī��Ʈüũ������
    //������1�� �Ѿ

    return answer;
}

int main()
{
    string numbers = "17";
    cout << solution(numbers);
}

// 1. ���� �� �ִ� ���� ū �� ���ϱ�
// - string�� �ϳ��� char�� �ɰ���
// - char�� �ɰ��� ������������ �����Ѵ�
// - char�� int�� �ٲ۴�
// => string ��ü�� sort ��ų �� �־���!
// => sort �� stoi�� �� ��ȯ��

// 2. �� ������ �Ҽ��� �� �Ǻ��ؼ�, �Ҽ��� ���Ϳ� �ֱ�
// => �Ҽ� �Ǻ��� ����¼����¼�� ü�� ������

// 3. ���� ���� numbers�� ���� �Ҽ��� �־�� ���Ϳ� �ֳ� ���� Ȯ��
// �ִ´�� ī������
// prime��

// 143 / 10 = 14..3 14 / 10 = 1..4 = > ���� �� ���̰� 1�̸� �׸�