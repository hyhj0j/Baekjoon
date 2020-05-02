// 124 나라의 숫자 ( https://programmers.co.kr/learn/courses/30/lessons/12899# )

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string dp(string n)
{
    string re = "";
    string last = "";
    string total = "";
    int intN = stoi(n);
    if (n == "1")
        return "1";
    else if (n == "2")
        return "2";
    else if (n == "3")
        return "4";
    else
    {
        // 40/3=13 -> 13/3=4 -> 4/3=1 -> 1
        int temp = intN / 3;
        if (intN % 3 == 0)
            temp = temp - 1;
        re += dp(to_string(temp)); //n=4일때, re=1=리턴값

        int temp2;

        if (intN % 3 == 0)
            temp2 = 4;
        else if (intN % 3 == 1)
            temp2 = 1;
        else if (intN % 3 == 2)
            temp2 = 2;

        last += (to_string(temp2)); //last=1=마지막값=1의자리값

        total = re + last; // string 덧셈이니까 "1"+"1" = "11"
    }
    return total;
}

string solution(int n)
{
    string answer = "";

    return dp(to_string(n));
}

// 효율성 테스트 두개 뭔데... 하.....
// 그래도 수고했다 나... 멋지다 대단하다 나..

// 채점을 시작합니다.
// 정확성  테스트
// 테스트 1 〉	통과 (0.02ms, 3.98MB)
// 테스트 2 〉	통과 (0.01ms, 3.89MB)
// 테스트 3 〉	통과 (0.01ms, 3.93MB)
// 테스트 4 〉	통과 (0.02ms, 3.85MB)
// 테스트 5 〉	통과 (0.02ms, 3.88MB)
// 테스트 6 〉	통과 (0.02ms, 3.84MB)
// 테스트 7 〉	통과 (0.03ms, 3.95MB)
// 테스트 8 〉	통과 (0.01ms, 3.97MB)
// 테스트 9 〉	통과 (0.01ms, 3.9MB)
// 테스트 10 〉	통과 (0.02ms, 3.84MB)
// 테스트 11 〉	통과 (0.02ms, 4MB)
// 테스트 12 〉	통과 (0.02ms, 3.91MB)
// 테스트 13 〉	통과 (0.02ms, 4MB)
// 테스트 14 〉	통과 (0.02ms, 3.89MB)
// 효율성  테스트
// 테스트 1 〉	실패 (시간 초과)
// 테스트 2 〉	실패 (시간 초과)
// 테스트 3 〉	통과 (0.02ms, 3.98MB)
// 테스트 4 〉	통과 (0.02ms, 3.84MB)
// 테스트 5 〉	통과 (0.02ms, 3.92MB)
// 테스트 6 〉	통과 (0.02ms, 3.85MB)
// 채점 결과
// 정확성: 70.0
// 효율성: 20.0
// 합계: 90.0 / 100.0