#include <iostream>
using namespace std;
int main()
{
    int x, y, date, dates = 0, result;
    string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    cin >> x >> y;

    for (int i = 1; i <= x; i++)
    {
        switch (i)
        {
        case 1:
            date = 0;
            break;
        case 3:
            date = 28;
            break;
        case 2:
        case 4:
        case 6:
        case 8:
        case 9:
        case 11:
            date = 31;
            break;
        case 5:
        case 7:
        case 10:
        case 12:
            date = 30;
            break;
        }
        dates += date;
    }
    dates += y;
    result = dates % 7;

    cout << day[result];
    // switch (result)
    // {
    // case 0:
    //     cout << day[0];
    //     break;
    // case 1:
    //     cout << day[1];
    //     break;
    // case 2:
    //     cout << day[2];
    //     break;
    // case 3:
    //     cout << day[3];
    //     break;
    // case 4:
    //     cout << day[4];
    //     break;
    // case 5:
    //     cout << day[5];
    //     break;
    // case 6:
    //     cout << day[6];
    //     break;
    // }
}