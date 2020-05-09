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

void div(int nums, bool str[]) // 어떤 수들이 쓰인지 확인하는 함수
{
    while (1)
    { // numbers에 들어간 숫자 bool형에 true로 표시하기

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

    sort(numbers.begin(), numbers.end(), greater<int>()); // 소수 구하기
    nums = stoi(numbers);
    fillPrime(nums);

    for (int i = 0; i < prime.size(); i++)
    {
        for (int j = 0; j < prime[i].size(); j++)
        {
        }
    }
    //프라임0의 string 0번쨰 자리에 있는 수가 str == true인지 확인
    //맞으면 카운트
    //아니면 카운트 안하고 프라임0의 string 1번째로 넘어감
    //프라임0의 string 길이 만큼 다 카운트체크했으면
    //프라임1로 넘어감

    return answer;
}

int main()
{
    string numbers = "17";
    cout << solution(numbers);
}

// 1. 만들 수 있는 가장 큰 수 구하기
// - string을 하나씩 char로 쪼갠다
// - char로 쪼갠걸 내림차순으로 정렬한다
// - char를 int로 바꾼다
// => string 자체를 sort 시킬 수 있었음!
// => sort 후 stoi로 형 변환함

// 2. 그 수까지 소수인 수 판별해서, 소수만 벡터에 넣기
// => 소수 판별은 에어쩌고저쩌고 체로 구했음

// 3. 내가 가진 numbers의 수가 소수만 넣어둔 벡터에 있나 없나 확인
// 있는대로 카운팅함
// prime을

// 143 / 10 = 14..3 14 / 10 = 1..4 = > 나눈 값 길이가 1이면 그만