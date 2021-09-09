//https://www.acmicpc.net/problem/10844
#include <iostream>
using namespace std;

uint64_t easystairsf(int n, int num, int layer, uint64_t **tmp)
{
    if (layer >= n - 1)
        return 1;

    if (tmp[num][layer] != 0)
        return tmp[num][layer];

    if (num == 0)
        tmp[num][layer] = easystairsf(n, num + 1, layer + 1, tmp)
            % 1000000000;
    else if (num == 9)
        tmp[num][layer] = easystairsf(n, num - 1, layer + 1, tmp)
            % 1000000000;
    else
        tmp[num][layer] = easystairsf(n, num - 1, layer + 1, tmp)
            + easystairsf(n, num + 1, layer + 1, tmp) % 1000000000;

    return tmp[num][layer] % 1000000000;
}

uint64_t easystairs(int n)
{
    uint64_t result = 0;
    uint64_t **tmp = new uint64_t*[10];
    for (int i=0; i < 10; i++)
        tmp[i] = new uint64_t[n] { 0, };

    for (int j=1; j <= 9; j++)
        result += easystairsf(n, j, 0, tmp);

    return result % 1000000000;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << easystairs(n) << '\n';
}