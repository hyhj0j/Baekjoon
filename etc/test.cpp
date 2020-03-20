// vector? find?? ????

#include <algorithm> // std::find
#include <iostream>  // std::cout
#include <vector>    // std::vector

using namespace std;

int main()
{

    vector<int> myvector;
    vector<int> node[100];
    vector<int>::iterator it; //???

    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);
    myvector.push_back(40);

    int target = 30;

    it = find(myvector.begin(), myvector.end(), target); // ?? target?? myvector? ??? myvector.end()? ???

    if (it != myvector.end()) //myvector.end()?? ??? == target? ???
        cout << "Element found in myvector: " << *it << '\n'; //it? ????? * ??? ???? ???
    else
        cout << "Element not found in myvector\n";

    return 0;
}