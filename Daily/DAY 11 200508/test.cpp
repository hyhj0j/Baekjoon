#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    string s = "123456789";
    cout << "1�� : " << s[1] << endl;
    const char *c = s.c_str();
    cout << "2�� : " << c[1] << endl;
    const char x = c[1];
    cout << "3�� : " << x << endl;
    int i = atoi(x);
    cout << "4�� : " << i;
}