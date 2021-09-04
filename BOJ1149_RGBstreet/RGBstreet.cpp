//https://www.acmicpc.net/problem/1149
#include <iostream>
using namespace std;

#define R 0
#define G 1
#define B 2

int getmin(int a, int b, int c=-1)
{
    int result = 0;
    result = a < b ? a : b;
    result = c != -1 && c < result ? c : result;

    return result;
}

int rgbstreet(int **rgb, int length)
{
    int **rgbroutes = new int*[length];

    rgbroutes[0] = new int[3];
    rgbroutes[0] = rgb[0];
    for (int i=1; i < length; i++)
    {
        rgbroutes[i] = new int[3];
        rgbroutes[i][R] = rgb[i][R]
        + getmin(rgbroutes[i - 1][G], rgbroutes[i - 1][B]);
        rgbroutes[i][G] = rgb[i][G]
        + getmin(rgbroutes[i - 1][R], rgbroutes[i - 1][B]);
        rgbroutes[i][B] = rgb[i][B]
        + getmin(rgbroutes[i - 1][R], rgbroutes[i - 1][G]);
    }

    return getmin(rgbroutes[length - 1][R], 
    rgbroutes[length - 1][G], rgbroutes[length - 1][B]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int **rgbarr = new int*[n];
    for (int i=0; i < n; i++)
    {
        rgbarr[i] = new int[3];
        cin >> rgbarr[i][0] >> rgbarr[i][1] >> rgbarr[i][2];
    }

    cout << rgbstreet(rgbarr, n) << '\n';
}