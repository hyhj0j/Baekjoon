#include <iostream>
#include <string>

using namespace std;

int main()
{

    string a = " 5 6 7 8 9 10 ";
    string b = "1 2 3 4 5 6 7 8 9 10 11 21 31 41 ";

    cout << b.compare(7, a.size(), a);
}