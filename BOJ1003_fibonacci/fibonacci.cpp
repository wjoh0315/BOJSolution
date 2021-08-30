//https://www.acmicpc.net/problem/1003
#include <iostream>
using namespace std;

void fibonacci(int current, int *count0, int *count1, int temp[41][2])
{
    if (current == 0)
    {
        *count0 += 1;
        return;
    }
    else if (current == 1)
    {
        *count1 += 1;
        return;
    }

    if (temp[current][0] != 0 && temp[current][1] != 0)
    {
        *count0 += temp[current][0];
        *count1 += temp[current][1];
        return;
    }
        
    fibonacci(current - 1, count0, count1, temp);
    fibonacci(current - 2, count0, count1, temp);

    temp[current][0] = *count0;
    temp[current][1] = *count1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int n;
    int count0 = 0;
    int count1 = 0;
    int temp[41][2] = { { 0, } };
        
    for (int i=0; i < t; i++)
    {
        cin >> n;
        fibonacci(n, &count0, &count1, temp);
        cout << count0 << ' ' << count1 << '\n';
        count0 = 0;
        count1 = 0;
    }
}