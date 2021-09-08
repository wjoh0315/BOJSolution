//https://www.acmicpc.net/problem/1463
#include <iostream>
using namespace std;

int maketo1min(int n)
{
    int *routes = new int[n];
    routes[0] = 0;
    routes[1] = 1;
    routes[2] = 1;
    for (int i=3; i < n; i++)
    {
        int min = routes[i - 1];
        if ((i + 1) % 3 == 0)
            min = min > routes[(i + 1) / 3 - 1] 
                ? routes[(i + 1) / 3 - 1] : min;
        if ((i + 1) % 2 == 0)
            min = min > routes[(i + 1) / 2 - 1] 
                ? routes[(i + 1) / 2 - 1] : min;
        routes[i] = min + 1;
    }
    return routes[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << maketo1min(n) << '\n';
}