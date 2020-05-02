
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "@@@@@ compare, substr, find, replace, swap 함수 템플릿 @@@@@\n";
    cout << "str.compare(str2) / str.compare(idx1, idx2, str2)\n";     // str과 str2비교, str의 [idx1]~[idx2]를 str2와 비교
    cout << "str.substr() / str.substr(idx) / str.substr(idx, num)\n"; // str 전체 / str의 [idx]~[str.length()-1] / str의 [idx]~[idx+num-1]
    cout << "str.find(str2) / str.find(str2, idx)\n";                  // str2가 시작하는 str의 인덱스 / str의 [idx]부터 str2를 찾아 발견하는 첫 인덱스
    cout << "str.replace(idx, num, str2)\n";                           // str의 idx부터 num개 요소를 str2로 대체.
    cout << "swap(str, str2)\n";                                       // str과 str2를 바꾸는 call-by-reference 함수.
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n";

    cout << "*****************1. compare 함수 *****************\n";
    cout << "#####################################################" << '\n';

    cout << "compare 함수 생김새 1-1: str.compare(str2)\n이 경우 str이 str2와 같다면 0을 반환.\n";
    cout << "compare 함수 생김새 1-2: str.compare(idx1, idx2, str2)\n이 경우 str의 idx1부터 idx2까지가 str2와 같다면 0을 반환.\n";
    cout << "#####################################################"
         << "\n\n\n";

    string str1 = "abcdefg";
    string str2 = "ABCDEfg";

    // compare
    cout << "str1: " << str1 << '\n';
    cout << "str2: " << str2 << '\n';
    cout << "!str1.compare(5, str1.size() - 1, str2.substr(5, 2)) 결과(같다면 0): \n"
         << str1.compare(5, str1.size() - 1, str2.substr(5, 2)) << '\n';
    if (!str1.compare(5, str1.size() - 1, str2.substr(5, 2)))
    {
        // str1.compare(idx1, idx2, str2) --> str1의 인덱스 idx1부터 idx2가 str2와 같으면 0반환.
        // 만약 다를경우 str1이 사전순으로 str2보다 빠르다면 -1반환, 반대라면 1반환.
        // str2.substr(idx1, num) --> str2의 인덱스 idx1부터 num개 문자열 반환.
        cout << "같으므로 .. str1 출력 --> ";
        cout << str1 << '\n';
        cout << "\n\n!!!!참고로 str.substr(3, 2)는 str의 인덱스 3번째부터 2개 추린 문자열 반환\n";
        cout << "str.substr();은 str 전체 반환, str.substr(3);은 str의 인덱스 3부터 끝까지 반환!!!!\n";
    }
    cout << "\n";
    string str3 = "abc";
    string str4 = "abc";
    if (!str3.compare(str4))
    {
        cout << "str3 :" << str3 << '\n';
        cout << "str4 :" << str4 << '\n';
        cout << "str3.compare(str4)의 결과는 0이므로 !str3.compare(str4)의 결과가 참이 됨.\n";
    }
    cout << "\n\n\n";

    // find
    cout << "***************2. find 함수 ***************\n";
    cout << "#####################################################" << '\n';

    cout << "find 함수 생김새 2-1: str.find(str2)\n이 경우 str의 첫 인덱스부터 str2를 찾아 str2가 시작하는 곳의 인덱스를 반환.\n";
    cout << "find 함수 생김새 2-2: str.compare(str2, idx)\n이 경우 str의 인덱스 idx부터 찾아 str2가 시작하는 인덱스를 반환.\n";
    cout << "#####################################################"
         << "\n\n\n";
    string find_str1 = "abcdefg";
    string find_str2 = "1234567";
    string find_str3 = "abcdefgdefg";
    cout << "find_str1: " << find_str1 << '\n';
    cout << "find_str2: " << find_str2 << '\n';
    cout << "find_str1.find(\"defg\") 결과: " << find_str1.find("defg") << '\n';
    cout << "find 함수 내 문자열이 시작하는 인덱스를 반환합니다.\n\n";

    cout << "find_str1.find(\"defg\", 4) 결과: " << find_str1.find("defg", 4) << '\n';
    cout << "인덱스 4부터 찾아서 못찾은 결과입니다. 3부터 찾는다면? \n";
    cout << "find_str1.find(\"defg\", 3) 결과: " << find_str1.find("defg", 3) << '\n';
    cout << "인덱스 3부터 찾으니 찾을 수 있었습니다. 결과는 " << find_str1.find("defg", 3) << "입니다.\n\n";

    cout << "만약 find_str1 대신 find_str3 (" << find_str3 << ")을 사용하면 어떻게 될까요?\n";
    cout << "find_str3.find(\"defg\") 결과: " << find_str3.find("defg") << '\n';
    cout << find_str3 << "에서 "
         << "defg를 찾은 결과 앞에서부터 찾다가 발견하면 해당 인덱스를 반환하는군요.\n";
    cout << "그러면 아까 인덱스 4부터 찾아서 못찾은 경우에도 적용해보겠습니다.\n";
    cout << "find_str3.find(\"defg\") 결과: " << find_str3.find("defg", 4) << '\n';
    cout << "이번에는 찾을 수 있었습니다.!\n";

    cout << "\n\n\n";

    // replace
    cout << "*******************3. replace 함수 *******************\n";
    cout << "#####################################################" << '\n';

    cout << "replace 함수 생김새 3-1: str.replace(idx, num, str2)\n이 경우 str의 인덱스 idx부터 num개를 str2로 대체하는 것.\n";
    cout << "#####################################################"
         << "\n\n\n";

    string replace_str = "ABCDEFG";
    string insert_str = "123456";
    cout << "replace_str: " << replace_str << '\n';
    cout << "insert_str: " << insert_str << '\n';
    cout << "replace_str.replace(2, 3, insert_str)의 결과는: " << replace_str.replace(2, 3, insert_str) << "\n\n\n";

    // swap
    cout << "*******************4. swap 함수 *******************\n";
    cout << "#####################################################" << '\n';
    cout << "swap 함수 생김새 4-1: swap(str, str2)\n 이 함수는 call-by-reference 함수임.\n";
    cout << "#####################################################"
         << "\n\n\n";

    string STR1 = "ABCDEFG";
    string STR2 = "12345678";
    cout << "STR1: " << STR1 << '\n';
    cout << "STR2: " << STR2 << '\n';
    cout << "swap(STR1, STR2) 시행\n";
    swap(STR1, STR2);
    cout << "STR1: " << STR1 << '\n';
    cout << "STR2: " << STR2 << '\n';

    return 0;
}