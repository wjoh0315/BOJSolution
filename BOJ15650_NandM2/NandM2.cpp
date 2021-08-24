//https://www.acmicpc.net/problem/15650
#include <iostream>
using namespace std;

void printsequencef(int n, int m, int cur, int current[8], int pre[8])
{
    if (m <= 0)
    {
        for (int i=0; i < 8; i++)
        {
            if (current[i] == 0)
                break;
            cout << current[i] << ' ';
        }

        cout << '\n';
    }
    else 
    {
        for (int i=0; i < n; i++)
        {
            if (pre[i] == 0)
            {
                if (current[cur - 1] >= i + 1)
                    continue;
                
                pre[i] = 1;
                current[cur] = i + 1;
                printsequencef(n, m - 1, cur + 1, current, pre);
                pre[i] = 0;
            }
        }   
    }
}

void printsequence(int n, int m)
{
    int current[8] = { 0, };
    int pre[8] = { 0, };
    printsequencef(n, m, 0, current, pre);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    printsequence(n, m);
}