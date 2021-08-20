//https://www.acmicpc.net/problem/11729
#include <iostream>
using namespace std;

void hanoi(int n, int from, int remain, int target)
{
    if (n <= 0)
        return;
    else if (n == 1)
        cout << from << ' ' << target << '\n';
    else
    {
        hanoi(n - 1, from, target, remain);
        hanoi(1, from, remain, target);
        hanoi(n - 1, remain, from, target);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int in;
    cin >> in;
    
    cout << (1 << in) - 1 << '\n';
    hanoi(in, 1, 2, 3);
}