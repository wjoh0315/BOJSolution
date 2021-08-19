#include <iostream>
#include <cstring>
using namespace std;

int decom(int sum)
{
    if (sum < 11)
        return 0;
    else 
    {
        char toChar[7];
        sprintf(toChar, "%d", sum);
        int digit = (int)strlen(toChar);

        bool loop = true;
        int current = sum > (toChar[0] - '0' - 1) + 9 * (digit - 1) 
            ? sum - (toChar[0] - '0' - 1) + 9 * (digit - 1) : sum;
        while (loop)
        {
            current++;
            
            char toChar[7];
            sprintf(toChar, "%d", current);

            int remain = 0;
            for (int i=0; i < digit; i++)
                remain += toChar[i] - '0';

            loop = sum != current + remain;
        }

        return current;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int in;
    cin >> in;

    cout << decom(in);
}