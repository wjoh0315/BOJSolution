//https://www.acmicpc.net/problem/10870
#include <iostream>
using namespace std;

uint32_t fibonacci(uint32_t current)
{
    if (current == 0)
        return 0;
    else if (current == 1)
        return 1;
    else
        return fibonacci(current - 1) 
            + fibonacci(current - 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    uint32_t in;
    cin >> in;
    cout << fibonacci(in);
}