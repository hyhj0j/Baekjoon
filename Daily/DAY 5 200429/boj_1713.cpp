#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    int totalRefer;
    cin >> totalRefer;
    queue<int> q;
    vector<pair<int, int>> frame; // (n, {0,0}); // studnet number , time
    int cntRefer[101] = {0};      // 1~100
    for (int i = 0; i < totalRefer; i++)
    {
        cin >> x;
        q.push(x);
    }

    int time = 0;

    while (!q.empty())
    {

        int z = q.front();
        q.pop();
        bool isInsideFrame = false;
        for (int i = 0; i < n; i++)
        {
            if (!frame.empty() && frame[i].first == z)
            {
                isInsideFrame = true;
                break;
            }
        }
        if (isInsideFrame == false)
        { // 프레임에 없으면 넣어줌
            if (frame.size() != n)
            {
                frame.push_back({z, time});
                cntRefer[z]++;
            }

            else
            { // 프레임 꽉 참
                int idx = 0;
                // 추천 수 제일 낮고, 오래된 애
                for (int i = 1; i < n; i++)
                {
                    if (cntRefer[frame[i].first] == cntRefer[frame[idx].first])
                    {
                        if (frame[i].second < frame[idx].second)
                            idx = i;
                    }
                    else if (cntRefer[frame[i].first] < cntRefer[frame[idx].first])
                    {
                        idx = i;
                    }
                }

                int deleteStudent = frame[idx].first;

                for (int i = 0; i < n; i++) // 찾은 애 프레임에서 삭제하기
                {
                    if (frame[i].first == deleteStudent)
                    {
                        if (i == 0)
                            frame.erase(frame.begin());
                        else
                        {
                            frame.erase(frame.begin() + i - 1);
                            cntRefer[deleteStudent] = 0;
                        }
                        break;
                    }
                }
                frame.push_back({z, time}); // 삭제 뒤 확보된 프레임에 새로운 애 넣기
                cntRefer[z]++;
            }
        }
        else
        { // 프레임에 있으면 수 ++ 해줌
            cntRefer[z]++;
        }

        //넣을 학생이 틀에 이미 들어있나 확인
        //학생 넣어줌
        //겹치는 학생은 cnt++ 해줌
        //틀 꽉차면, 프레임 안에서 추천 적은 애 삭제
        // -추천 수 같으면, 젤 오래된 애 삭제

        time++;
    }

    sort(frame.begin(), frame.end());
    for (int i = 0; i < n; i++)
        cout << frame[i].first << " ";

    return 0;
}