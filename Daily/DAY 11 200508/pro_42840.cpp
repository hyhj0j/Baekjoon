#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    int s1[] = {1, 2, 3, 4, 5};
    int s2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int s3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    pair<int, int> a[3];
    int n = answers.size();
    int i = 0;
    a[0] = {1, 0};
    a[1] = {2, 0};
    a[2] = {3, 0};

    while (i < n)
    {
        if (s1[i % 5] == answers[i])
            a[0].second++;
        if (s2[i % 8] == answers[i])
            a[1].second++;
        if (s3[i % 10] == answers[i])
            a[2].second++;
        i++;
    }

    sort(a, a + 3, cmp);
    answer.push_back(a[0].first);
    if (a[0].second == a[1].second)
        answer.push_back(a[1].first);
    if (a[0].second == a[2].second)
        answer.push_back(a[2].first);

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";

    return answer;
}

int main()
{
    vector<int> v = {1, 3, 2, 4, 2};
    solution(v);
}

// 좀 더 간단하게 ? 푼 것

// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// int getMax(int a, int b, int c){
//     int max = a > b ? a : b;
//     max = max > c ? max : c;
//     return max;
// }
// vector<int> solution(vector<int> answers)
// {
//     vector<int> answer;
//     int s1[] = {1, 2, 3, 4, 5};
//     int s2[] = {2, 1, 2, 3, 2, 4, 2, 5};
//     int s3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
//     int a[3] = {0};
//     int n = answers.size();
//     int i = 0;

//     while (i < n)
//     {
//         if (s1[i%5] == answers[i])
//             a[0]++;
//         if (s2[i % 8] == answers[i])
//             a[1]++;
//         if (s3[i % 10] == answers[i])
//             a[2]++;
//         i++;
//     }

//     int max = getMax(a[0], a[1], a[2]);
//     for(int i=0; i<3; i++){
//         if(a[i] == max) answer.push_back(i+1);
//     }

//     return answer;
// }