// 세훈이의 선물가게 ( https://www.acmicpc.net/problem/17225 )
// (100/140) : SUB2 케이스 넘 어려워서 손 못대고 SUB1만 풀었음 ㅠㅠ

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    int order[n + 1][3]; // order[1][3] 부터 시작
    for (int i = 1; i <= n; i++)
    {
        int t, m;
        char c;
        cin >> t >> c >> m;
        if (c == 'B')
            order[i][1] = 0; // 파랑이면 0
        else
            order[i][1] = 1; // 빨강이면 1
        order[i][0] = t;
        order[i][2] = m;
    }

    vector<int> blue, red; //상민, 지수
    int cntblue = 0, cntred = 0;
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        if (order[i][1] == 0)
        {
            cntblue += order[i][2];
            for (int j = 0; j < order[i][2]; j++)
            {
                blue.push_back(k);
                k++;
            }
        }
        else if (order[i][1] == 1)
        {
            cntred += order[i][2];
            for (int j = 0; j < order[i][2]; j++)
            {
                red.push_back(k);
                k++;
            }
        }
    }

    cout << cntblue << "\n";
    for (int i = 0; i < blue.size(); i++)
    {
        cout << blue[i] << " ";
    }
    cout << "\n"
         << cntred << "\n";
    for (int i = 0; i < red.size(); i++)
    {
        cout << red[i] << " ";
    }
}

// 상민, 지수 각각이 끝낸 수 카운트해야됨
// 카운트될때 index(=몇번째 선물인지 표시한 것)도 배열에 저장해야됨 => 오름차순으로 출력
// 동시에 포장 가능시엔 상민 우선!
// 주문&시작 , 주문&끝