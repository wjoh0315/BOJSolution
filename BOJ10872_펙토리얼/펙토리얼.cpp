#include <iostream>
using namespace std;

int factorial(uint32_t current)
{
    if (current == 0 || current == 1)
        return 1;

    uint32_t result = 1;
    for (uint32_t i=2; i <= current; i++)
    {
        result *= i;
    }
    
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    uint32_t in;
    cin >> in;
    cout << factorial(in);
}