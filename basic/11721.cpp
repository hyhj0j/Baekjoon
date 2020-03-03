#include <iostream>
#include <string>
using namespace std;
int main()
{
    string words;
    getline(cin, words);

    for (int i = 0; i < words.length(); i++)
    {
        cout << words[i];
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
}