//https://www.acmicpc.net/problem/1904
#include <iostream>
using namespace std;

int tile(int current, int temp[2])
{
    if (current == 1)
        return 1;
    else if (current == 2)
        return 2;

    int sum = 0;
    for (int i=0; i < current - 2; i++)
    {
        sum = temp[0] + temp[1];
        temp[0] = temp[1];
        temp[1] = sum % 15746;
    }
    
    return temp[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int in;
    cin >> in;

    int temp[2] = { 1, 2 };
    cout << tile(in, temp) << '\n';
}