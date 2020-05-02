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
        { // �����ӿ� ������ �־���
            if (frame.size() != n)
            {
                frame.push_back({z, time});
                cntRefer[z]++;
            }

            else
            { // ������ �� ��
                int idx = 0;
                // ��õ �� ���� ����, ������ ��
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

                for (int i = 0; i < n; i++) // ã�� �� �����ӿ��� �����ϱ�
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
                frame.push_back({z, time}); // ���� �� Ȯ���� �����ӿ� ���ο� �� �ֱ�
                cntRefer[z]++;
            }
        }
        else
        { // �����ӿ� ������ �� ++ ����
            cntRefer[z]++;
        }

        //���� �л��� Ʋ�� �̹� ����ֳ� Ȯ��
        //�л� �־���
        //��ġ�� �л��� cnt++ ����
        //Ʋ ������, ������ �ȿ��� ��õ ���� �� ����
        // -��õ �� ������, �� ������ �� ����

        time++;
    }

    sort(frame.begin(), frame.end());
    for (int i = 0; i < n; i++)
        cout << frame[i].first << " ";

    return 0;
}