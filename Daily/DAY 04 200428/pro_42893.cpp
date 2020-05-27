#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

char ifUpperSwapLower(char c)
{
    return 'A' <= c && c <= 'Z' ? c - 'A' + 'a' : c;
}

int solution(string word, vector<string> pages)
{
    for (int i = 0; i < word.size(); i++)
    {
        word[i] = ifUpperSwapLower(word[i]);
    }

    int N = pages.size();
    unordered_map<string, int> linkAndWebIndexMap;                   //��ũ, web�ε���
    vector<pair<int, vector<string>>> web(N, {0, vector<string>()}); // N���� (�⺻����, ��ũ����Ʈ)�� �ʱ�ȭ
    for (int i = 0; i < N; i++)
    {
        string html = pages[i];
        int j = 0;
        string nowLink = "";
        int ind = 0;
        while (nowLink == "")
        {
            ind = html.find("<meta") + 5;
            int last = html.substr(ind).find(">");
            html = html.substr(ind);
            ind = html.find("https://");

            // meta �±� �ȿ� �ִ� ��ũ�� �ƴѰ�� �Ÿ���
            if (last < ind)
                continue;
            while (html[ind] != '\"')
            {
                nowLink += html[ind++];
            }
            linkAndWebIndexMap[nowLink] = i;
        }

        //body ã��
        int startBodyInd = html.find("<body>") + 6;
        int lastBodyInd = html.find("</body>");

        // �⺻ ���� ���ϱ�
        string tmp = "";
        bool nowInBracket = false;
        for (int j = startBodyInd; j < lastBodyInd; j++)
        {
            char nowC = ifUpperSwapLower(html[j]);
            if (nowInBracket)
            {
                if (nowC == '>')
                    nowInBracket = false;
            }
            else if (nowC == ' ' || !('a' <= nowC && nowC <= 'z'))
            {
                if (tmp != "" && tmp == word)
                    web[i].first++; // �⺻ ���� �߰�
                tmp = "";
                if (nowC == '<')
                    nowInBracket = true;
            }
            else
            {
                tmp += nowC;
            }
        }
        if (tmp != "" && tmp == word)
            web[i].first++; // �⺻ ���� �߰�

        // ��ũ ���� ���ϱ�
        tmp = html.substr(startBodyInd);
        ind = tmp.find("<a href");
        while (ind != string::npos)
        {
            tmp = tmp.substr(ind + 7);
            tmp = tmp.substr(tmp.find("https://"));
            web[i].second.push_back(tmp.substr(0, tmp.find("\"")));
            ind = tmp.find("<a href");
        }
    }

    // ��Ī ����
    vector<double> matchingScore(N, 0);
    for (int i = 0; i < N; i++)
    {
        matchingScore[i] += web[i].first;
        double linkScore = 0;
        if (web[i].second.size() != 0)
            linkScore = (double)web[i].first / (double)web[i].second.size();
        for (int j = 0; j < web[i].second.size(); j++)
        {
            printf("end : %d \n", linkAndWebIndexMap.end());
            printf("find : %d ", linkAndWebIndexMap.find(web[i].second[j]));
            /* if (linkAndWebIndexMap.find(web[i].second[j]) != linkAndWebIndexMap.end()) 
            �� �κ� �ؼ��ϱ� ���� ���� �ܾ��.

            =>  if(strMap.end() == strMap.find(elem))
                �� �κ��� ��մµ� map�� key���� ������ ������ ���� ǥ���ߴ�.
                .end() �޼ҵ�� �ڷ��� ���������� �������� ��iterator�� �޸𸮸� ��ȯ�Ѵ�.
                .find() �޼ҵ� ���� iterator�� ��ȯ�ϴµ� �� �� ã�� ���� ��� ���� �� iterator�� ��ȯ�Ѵ�.  

                ��, map.end()�� �׻� �� �޸� 0�� ��ȯ��
                linkAndWebIndexMap�� ã�� ���� ������ 0�� ��ȯ�� 
                �ٽ� �����ڸ�, pages�� �����ϴ� �ܺθ�ũ�� �����ɶ��� if���� ����� �Ҹ�.
            */
            if (linkAndWebIndexMap.find(web[i].second[j]) != linkAndWebIndexMap.end())
            {
                int linkInd = linkAndWebIndexMap[web[i].second[j]];
                matchingScore[linkInd] += linkScore;
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        if (matchingScore[answer] < matchingScore[i])
            answer = i;
    }
    return answer;
}

int main()
{
    vector<string> v = {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"};
    solution("blind", v);
}