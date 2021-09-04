//https://www.acmicpc.net/problem/1932
#include <iostream>
using namespace std;

int clamp(int v, int min, int max)
{
    if (v < min)
        return min;
    else if (v > max)
        return max;

    return v;
}

int getmax(int *arr, int start, int end)
{
    int max = 0;
    for (int i=start; i < end; i++)
        max = i == start || arr[i] > max 
            ? arr[i] : max; 

    return max;
}

int inttriangle(int *tri, int side)
{
    int length = (1 + side) * side / 2;
    int *routes = new int[length];
    int cur = 0;

    routes[0] = tri[0];
    for (int i=1; i < side; i++)
    {
        //cout << i << "  ";

        for (int j=0; j < i + 1; j++)
        {
            cur++;
            routes[cur] = tri[cur] 
            + getmax(routes, clamp(cur - i - 1, cur - i - j, cur - j), 
            clamp(cur - i + 1, cur - i - j, cur - j));

            //cout << routes[cur] << ' ';
        }

        //cout << '\n';
    }

    return getmax(routes, length - 1 - side, length);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int *triarr = new int[(1 + n) * n / 2];
    for (int i=0; i < (1 + n) * n / 2; i++)
        cin >> triarr[i];

    cout << inttriangle(triarr, n) << '\n';
}