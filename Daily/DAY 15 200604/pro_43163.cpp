#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 51;

void dfs(string begin, string target, vector<string> words, vector<bool> &useCheck, int cnt = 0)
{
    for (int i = 0; i < words.size(); i++)
    { // i �ܾ�
        int count = 0;
        for (int j = 0; j < words[j].length(); j++)      // j �ܾ� �� ���ĺ�
            if (!useCheck[i] && begin[j] != words[i][j]) //�ܾ ���ȵư�, ���۴ܾ� j��° ���ĺ��̶� i �ܾ� �� j��° ���ĺ� �ٸ���
                count++;
        if (count == 1)
        {
            if (target == words[i] && answer > cnt + 1)
            {
                answer = cnt + 1;
                return;
            }
            useCheck[i] = true;
            dfs(words[i], target, words, useCheck, cnt + 1);
            useCheck[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    vector<bool> useCheck(words.size(), false);
    dfs(begin, target, words, useCheck);
    if (answer == 51)
        return 0;
    return answer;
}

int main()
{
    int t = solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"});
    cout << t;
}