#include <iostream>
#include <cstring>
using namespace std;

int decom(int sum)
{
    char toChar[7];
    sprintf(toChar, "%d", sum);
    int digit = (int)strlen(toChar);

    bool loop = true;
    int current = sum > 9 * digit
        ? sum - 9 * digit : 0;
    while (loop && current < sum)
    {
        current++;
        
        char toChar[7];
        sprintf(toChar, "%d", current);
        int digit = (int)strlen(toChar);

        int remain = 0;
        for (int i=0; i < digit; i++)
            remain += toChar[i] - '0';

        loop = sum != current + remain;
    }

    if (loop)
        return 0;
    else
        return current;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int in;
    cin >> in;

    cout << decom(in);
}