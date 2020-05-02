#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int kkk = 3;
    for (int i = 0; i < 5; i++)
    {
        if (kkk > 0)
        {
            cout << "first if \n"; // ? ??? ?? ????
            if (i < kkk)
            {
                cout << "second if\n";
            }
            else
                break;
        }
    }
}