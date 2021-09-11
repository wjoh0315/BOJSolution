//https://www.acmicpc.net/problem/2156
#include <iostream>
using namespace std;

int getmax(int a, int b)
{
    return a>b?a:b;
}

int wine(int *stairs, int length)
{
    int **routes = new int*[length];
    
    routes[0] = new int[3];
    routes[0][0] = stairs[0];
    routes[0][1] = 0;
    routes[0][2] = 0;
    if (length == 1)
        return routes[0][0];

    routes[1] = new int[3];
    routes[1][0] = stairs[0] + stairs[1];
    routes[1][1] = stairs[1];
    routes[1][2] = 0;
    if (length == 2)
        return routes[1][0];

    for (int i=2; i < length; i++)
    {
        routes[i] = new int[3];
        routes[i][0] = stairs[i] + getmax(routes[i - 1][1], routes[i - 1][2]);
        routes[i][1] = stairs[i] + getmax(routes[i - 2][2], 
            getmax(routes[i - 2][0], routes[i - 2][1]));

        if (i >= 3)
            routes[i][2] = stairs[i] + getmax(routes[i - 3][2], 
                getmax(routes[i - 3][0], routes[i - 3][1]));
        else 
            routes[i][2] = 0;
    }

    return getmax(
        getmax(routes[length - 2][2], getmax(routes[length - 2][0], routes[length - 2][1])), 
        getmax(routes[length - 1][2], getmax(routes[length - 1][0], routes[length - 1][1]))
    );
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int *stairsarr = new int[n];
    for (int i=0; i < n; i++)
        cin >> stairsarr[i];

    cout << wine(stairsarr, n) << '\n';
}