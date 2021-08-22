//https://www.acmicpc.net/problem/2252
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;
    cin >> n;

    int countingarr[10001] = { 0, };
    for (int i=0; i < n; i++)
    {
        int in;
        cin >> in;
        countingarr[in]++;
    }

    for (int i=1; i < 10001; i++)
    {
        while (countingarr[i] > 0)
        {
            cout << i << '\n';
            countingarr[i]--;
        }
    }
}