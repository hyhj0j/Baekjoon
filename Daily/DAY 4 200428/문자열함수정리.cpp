
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "@@@@@ compare, substr, find, replace, swap �Լ� ���ø� @@@@@\n";
    cout << "str.compare(str2) / str.compare(idx1, idx2, str2)\n";     // str�� str2��, str�� [idx1]~[idx2]�� str2�� ��
    cout << "str.substr() / str.substr(idx) / str.substr(idx, num)\n"; // str ��ü / str�� [idx]~[str.length()-1] / str�� [idx]~[idx+num-1]
    cout << "str.find(str2) / str.find(str2, idx)\n";                  // str2�� �����ϴ� str�� �ε��� / str�� [idx]���� str2�� ã�� �߰��ϴ� ù �ε���
    cout << "str.replace(idx, num, str2)\n";                           // str�� idx���� num�� ��Ҹ� str2�� ��ü.
    cout << "swap(str, str2)\n";                                       // str�� str2�� �ٲٴ� call-by-reference �Լ�.
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n";

    cout << "*****************1. compare �Լ� *****************\n";
    cout << "#####################################################" << '\n';

    cout << "compare �Լ� ����� 1-1: str.compare(str2)\n�� ��� str�� str2�� ���ٸ� 0�� ��ȯ.\n";
    cout << "compare �Լ� ����� 1-2: str.compare(idx1, idx2, str2)\n�� ��� str�� idx1���� idx2������ str2�� ���ٸ� 0�� ��ȯ.\n";
    cout << "#####################################################"
         << "\n\n\n";

    string str1 = "abcdefg";
    string str2 = "ABCDEfg";

    // compare
    cout << "str1: " << str1 << '\n';
    cout << "str2: " << str2 << '\n';
    cout << "!str1.compare(5, str1.size() - 1, str2.substr(5, 2)) ���(���ٸ� 0): \n"
         << str1.compare(5, str1.size() - 1, str2.substr(5, 2)) << '\n';
    if (!str1.compare(5, str1.size() - 1, str2.substr(5, 2)))
    {
        // str1.compare(idx1, idx2, str2) --> str1�� �ε��� idx1���� idx2�� str2�� ������ 0��ȯ.
        // ���� �ٸ���� str1�� ���������� str2���� �����ٸ� -1��ȯ, �ݴ��� 1��ȯ.
        // str2.substr(idx1, num) --> str2�� �ε��� idx1���� num�� ���ڿ� ��ȯ.
        cout << "�����Ƿ� .. str1 ��� --> ";
        cout << str1 << '\n';
        cout << "\n\n!!!!����� str.substr(3, 2)�� str�� �ε��� 3��°���� 2�� �߸� ���ڿ� ��ȯ\n";
        cout << "str.substr();�� str ��ü ��ȯ, str.substr(3);�� str�� �ε��� 3���� ������ ��ȯ!!!!\n";
    }
    cout << "\n";
    string str3 = "abc";
    string str4 = "abc";
    if (!str3.compare(str4))
    {
        cout << "str3 :" << str3 << '\n';
        cout << "str4 :" << str4 << '\n';
        cout << "str3.compare(str4)�� ����� 0�̹Ƿ� !str3.compare(str4)�� ����� ���� ��.\n";
    }
    cout << "\n\n\n";

    // find
    cout << "***************2. find �Լ� ***************\n";
    cout << "#####################################################" << '\n';

    cout << "find �Լ� ����� 2-1: str.find(str2)\n�� ��� str�� ù �ε������� str2�� ã�� str2�� �����ϴ� ���� �ε����� ��ȯ.\n";
    cout << "find �Լ� ����� 2-2: str.compare(str2, idx)\n�� ��� str�� �ε��� idx���� ã�� str2�� �����ϴ� �ε����� ��ȯ.\n";
    cout << "#####################################################"
         << "\n\n\n";
    string find_str1 = "abcdefg";
    string find_str2 = "1234567";
    string find_str3 = "abcdefgdefg";
    cout << "find_str1: " << find_str1 << '\n';
    cout << "find_str2: " << find_str2 << '\n';
    cout << "find_str1.find(\"defg\") ���: " << find_str1.find("defg") << '\n';
    cout << "find �Լ� �� ���ڿ��� �����ϴ� �ε����� ��ȯ�մϴ�.\n\n";

    cout << "find_str1.find(\"defg\", 4) ���: " << find_str1.find("defg", 4) << '\n';
    cout << "�ε��� 4���� ã�Ƽ� ��ã�� ����Դϴ�. 3���� ã�´ٸ�? \n";
    cout << "find_str1.find(\"defg\", 3) ���: " << find_str1.find("defg", 3) << '\n';
    cout << "�ε��� 3���� ã���� ã�� �� �־����ϴ�. ����� " << find_str1.find("defg", 3) << "�Դϴ�.\n\n";

    cout << "���� find_str1 ��� find_str3 (" << find_str3 << ")�� ����ϸ� ��� �ɱ��?\n";
    cout << "find_str3.find(\"defg\") ���: " << find_str3.find("defg") << '\n';
    cout << find_str3 << "���� "
         << "defg�� ã�� ��� �տ������� ã�ٰ� �߰��ϸ� �ش� �ε����� ��ȯ�ϴ±���.\n";
    cout << "�׷��� �Ʊ� �ε��� 4���� ã�Ƽ� ��ã�� ��쿡�� �����غ��ڽ��ϴ�.\n";
    cout << "find_str3.find(\"defg\") ���: " << find_str3.find("defg", 4) << '\n';
    cout << "�̹����� ã�� �� �־����ϴ�.!\n";

    cout << "\n\n\n";

    // replace
    cout << "*******************3. replace �Լ� *******************\n";
    cout << "#####################################################" << '\n';

    cout << "replace �Լ� ����� 3-1: str.replace(idx, num, str2)\n�� ��� str�� �ε��� idx���� num���� str2�� ��ü�ϴ� ��.\n";
    cout << "#####################################################"
         << "\n\n\n";

    string replace_str = "ABCDEFG";
    string insert_str = "123456";
    cout << "replace_str: " << replace_str << '\n';
    cout << "insert_str: " << insert_str << '\n';
    cout << "replace_str.replace(2, 3, insert_str)�� �����: " << replace_str.replace(2, 3, insert_str) << "\n\n\n";

    // swap
    cout << "*******************4. swap �Լ� *******************\n";
    cout << "#####################################################" << '\n';
    cout << "swap �Լ� ����� 4-1: swap(str, str2)\n �� �Լ��� call-by-reference �Լ���.\n";
    cout << "#####################################################"
         << "\n\n\n";

    string STR1 = "ABCDEFG";
    string STR2 = "12345678";
    cout << "STR1: " << STR1 << '\n';
    cout << "STR2: " << STR2 << '\n';
    cout << "swap(STR1, STR2) ����\n";
    swap(STR1, STR2);
    cout << "STR1: " << STR1 << '\n';
    cout << "STR2: " << STR2 << '\n';

    return 0;
}