#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cin�� scanf���� 3���� ������ ������
    //�� ������ �߰��Ͽ� cin�� �ӵ��� ������

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\n"; // endl���� \n�� �ӵ��� ����
    }
}

//�̷��� �ڵ��ߴ��� �ð��ʰ�
//
//
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     for(int i=0; i<n ;i++){
//         cout << i+1 << endl;
//     }
// }