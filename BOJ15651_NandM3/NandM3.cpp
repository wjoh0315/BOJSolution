//https://www.acmicpc.net/problem/15651
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

void printsequencef(int n, int m, int cur, int current[7])
{
    if (m <= 0)
    {
        for (int i=0; i < 7; i++)
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
            current[cur] = i + 1;
            printsequencef(n, m - 1, cur + 1, current);
        }   
    }
}

void printsequence(int n, int m)
{
    int current[7] = { 0, };
    printsequencef(n, m, 0, current);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    printsequence(n, m);
}