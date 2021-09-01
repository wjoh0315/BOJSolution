//https://www.acmicpc.net/problem/9461
#include <iostream>
using namespace std;

uint64_t padovan(int current, uint64_t temp[3])
{
    if (current <= 3)
        return 1;

    uint64_t sum = 0;
    for (int i=0; i < current - 3; i++)
    {
        sum = temp[0] + temp[1];
        temp[0] = temp[1];
        temp[1] = temp[2];
        temp[2] = sum;
    }
    
    return temp[2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int in;
    for (int i=0; i < t; i++)
    {
        uint64_t temp[3] = { 1, 1, 1 };
        cin >> in;
        cout << padovan(in, temp) << '\n';
    }
}