// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWVl47b6DGMDFAXm&categoryId=AWVl47b6DGMDFAXm&categoryType=CODE#none

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    int n = t;

    vector<int> result;

    while (n > 0)
    {
        vector<int> lazer;
        vector<pair<int, int>> stick; //left, right 위치
        string input;
        cin >> input;
        int total = 0;
        bool isChecked[input.size()] = {false};
        for (int i = 1; i < input.size(); i++)
        { // 찾기
            if (input[i] == ')' && input[i - 1] == '(')
            { // 레이저 찾기
                lazer.push_back(i);
                isChecked[i] = true;
                isChecked[i - 1] = true;
            }
            else if (input[i] == ')')
            { // 쇠막대 찾기
                for (int j = i - 1; j >= 0; j--)
                {
                    if (!isChecked[j] && input[j] == '(')
                    {
                        isChecked[j] = true;
                        stick.push_back({j, i});
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < stick.size(); i++)
        {
            for (int j = stick[i].first; j <= stick[i].second; j++)
            {
                for (int k = 0; k < lazer.size(); k++)
                {
                    if (j == lazer[k])
                        total++;
                }
            }
        }
        result.push_back(total + stick.size());

        n--;
    }

    for (int i = 0; i < t; i++)
        cout << "#" << i + 1 << " " << result[i] << "\n";

    return 0;
}

/* 풀이 생각 정리
    1. right ) 얘를 먼저 찾고, 얘랑 제일 가까운 left ( 를 찾아
        1-1. 만약 right 바로 이전에 right가 있다? 그건 레이저임
            - 벡터에 레이저의 right 위치를 저장하자
        1-2. 바로 이전에 있지 않다? 그건 쇠막대임
            - pair로 만든 벡터에 쇠막대 시작과 끝을 저장하자
    2. 쇠막대 범위 안에 레이저벡터(2) right가 몇개 들어있나 확인
        - 확인한 레이저벡터+1 이 잘라진 쇠막대 개수




        ...............ㅠㅠ 결과값 다 잘 나오는데...
        시간초과..........하...............
        구글링해서 다른 사람들 솔루션보니...... 너무 간단하다...
        눈물...
*/

/*
    * 문제 * 
    자기보다 긴 막대 위에만 있을 수 있다
    그러나 겹친 막대들의 양끝점은 겹치지 않음
    레이저는 적어도 하나 존재
    그러나 레이저는 어떤 막대의 양끝점과도 겹치지 않음
    () => 레이저
    쇠막대 왼쪽 끝 = '(', 오른쪽 끝 = ')'
*/