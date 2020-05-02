#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int story[n + 1] = {0}; // story[0]은 비어있음
    // pair<int, int> findStoryNum[n + 1] = {{0, 0}}; // 왼쪽, 오른쪽
    int maxStory[n + 1] = {0};
    int maxLeftNum = 0, maxRightNum = 0;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> story[i];
    }
    int roopCnt = n;
    int i = 1;
    while (roopCnt != i)
    {
        int maxLeftNum = 0, maxRightNum = 0;
        double maxLine = 0, minLine = 1000;
        for (int left = i - 1; left > 0; left--)
        {
            double firstLine = (double)(story[i] - story[i - 1]) / 1;
            double line = (double)(story[left] - story[i]) / (left - i);
            if (firstLine > 0)
            { // 첫 라인이 양의 방향이면
                if (line < minLine)
                {
                    maxLeftNum++;
                    minLine = line;
                }
                else
                    break;
            }
            else
            { // 첫 라인이 음의 방향이면
                if (line > maxLine)
                {
                    maxLeftNum++;
                    maxLine = line;
                }
                else
                    break;
            }
        }

        for (int right = i + 1; right < n + 1; right++)
        {
            double firstLine = (double)(story[i] - story[i + 1]) / -1;
            double line = (double)(story[right] - story[i]) / (right - i);
            if (firstLine > 0)
            { // 첫 라인이 양의 방향이면
                if (line < minLine)
                {
                    maxRightNum++;
                    minLine = line;
                }
                else
                    break;
            }
            else
            { // 첫 라인이 음의 방향이면
                if (line > maxLine)
                {
                    maxRightNum++;
                    maxLine = line;
                }
                else
                    break;
            }
        }

        maxLeftNum >= maxRightNum ? maxStory[i] = maxLeftNum : maxStory[i] = maxRightNum;
        i++;
    }
    sort(maxStory, maxStory + n + 1);
    cout << maxStory[n];
}