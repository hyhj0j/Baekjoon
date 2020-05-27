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
    unordered_map<string, int> linkAndWebIndexMap;                   //링크, web인덱스
    vector<pair<int, vector<string>>> web(N, {0, vector<string>()}); // N개를 (기본점수, 링크리스트)로 초기화
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

            // meta 태그 안에 있는 링크가 아닌경우 거르기
            if (last < ind)
                continue;
            while (html[ind] != '\"')
            {
                nowLink += html[ind++];
            }
            linkAndWebIndexMap[nowLink] = i;
        }

        //body 찾기
        int startBodyInd = html.find("<body>") + 6;
        int lastBodyInd = html.find("</body>");

        // 기본 점수 구하기
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
                    web[i].first++; // 기본 점수 추가
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
            web[i].first++; // 기본 점수 추가

        // 링크 점수 구하기
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

    // 매칭 점수
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
            이 부분 해석하기 위해 예시 긁어옴.

            =>  if(strMap.end() == strMap.find(elem))
                이 부분이 재밌는데 map에 key값이 없음을 다음과 같이 표현했다.
                .end() 메소드는 자료의 마지막값의 다음값인 빈iterator의 메모리를 반환한다.
                .find() 메소드 역시 iterator를 반환하는데 이 때 찾지 못할 경우 역시 빈 iterator를 반환한다.  

                즉, map.end()는 항상 빈 메모리 0을 반환함
                linkAndWebIndexMap는 찾을 값이 없을때 0을 반환함 
                다시 말하자면, pages에 존재하는 외부링크가 참조될때만 if문을 돌라는 소리.
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