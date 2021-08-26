//https://www.acmicpc.net/problem/9663
#include <iostream>
using namespace std;

void queenf(int *queens, int *getables, int n, int cn)
{
    if (cn - 1 == n)
        *getables += 1;
    else
    {
        for (int x=0; x < n; x++)
        {
            bool able = cn == 1;
            for (int j=0; j < cn - 1; j++)
            {
                if (queens[j] != x && abs(cn - j - 1) != abs(x - queens[j]))
                {
                    able = true;
                }
                else
                {
                    able = false;
                    break;
                }
            }

            if (able)
            {
                queens[cn - 1] = x;
                queenf(queens, getables, n, cn + 1);
            }
        }
    }
}

int queen(int n)
{
    int *queens = new int[n];
    int getables = 0;
    queenf(queens, &getables, n, 1);
    return getables;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << queen(n) << '\n';
}