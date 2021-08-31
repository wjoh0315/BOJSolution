//https://www.acmicpc.net/problem/9184
#include <iostream>
using namespace std;

int w(int a, int b, int c, int temp[51][51][51])
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (temp[a][b][c] != 0)
        return temp[a][b][c];

    if (a > 20 || b > 20 || c > 20)
    {
        temp[a][b][c] = w(20, 20, 20, temp);
        return temp[a][b][c];
    }
    if (a < b && b < c)
    {
        temp[a][b][c] = w(a, b, c - 1, temp);
            + w(a, b - 1, c - 1, temp) - w(a, b - 1, c, temp);
        return temp[a][b][c];
    }

    temp[a][b][c] = w(a - 1, b, c, temp) + w(a - 1, b - 1, c, temp) 
        + w(a - 1, b, c - 1, temp) - w(a - 1, b - 1, c - 1, temp);
    return temp[a][b][c];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    int temp[51][51][51] = { { { 0, }, } };
    while (true)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        cout << w(a, b, c, temp) << '\n';
    }
}