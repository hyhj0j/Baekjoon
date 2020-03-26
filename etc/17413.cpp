#include <iostream>
#include <stack>
#include <string>

using namespace std;

void doSTH(stack<char> &s)
{
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}

int main()
{

    string str;
    getline(cin, str);
    bool tag = false;

    stack<char> s;

    for (char ch : str)
    {
        if (ch == '<')
        {
            doSTH(s);
            tag = true;
            cout << ch;
        }
        else if (ch == '>')
        {
            tag == false;
            cout << ch;
        }
        else if (tag)
        {
            cout << ch;
        }
        else
        {
            if (ch == ' ')
            {
                doSTH(s);
                cout << ch;
            }
            else
            {
                s.push(ch);
            }
        }
    }
    doSTH(s);
    cout << "\n";
    return 0;
}