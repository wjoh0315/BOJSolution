//https://www.acmicpc.net/problem/18870
#include <iostream>
using namespace std;

int binarysearch(int *current, int target, int start, int end)
{
    int cstart = start;
    int cend = end + 1;
    int mid = 0;
    bool isstart = false;
    while (cstart < cend)
    {
        mid = (cstart + cend) / 2;
        if (current[mid] >= target) cend = mid;
        else cstart = mid + 1;

        isstart = true;
    }

    if (isstart)
        return cstart;
    else
        return -1;
}

int mergesort(int *current, int *temp, int start, int end, bool root)
{
    if (start >= end) return 0;
    int mid = (start + end) / 2;
    mergesort(current, temp, start, mid, false);
    mergesort(current, temp, mid + 1, end, false);

    int compare1 = start;
    int compare2 = mid + 1;
    int skip = 0;
    for (int i=start; i < end - skip + 1; i++)
    {
        if (compare2 > end) temp[i] = current[compare1++];
        else if (compare1 > mid) temp[i] = current[compare2++];
        else if (current[compare1] <= current[compare2])
            temp[i] = current[compare1++];
        else temp[i] = current[compare2++];

        if (root && i > 0)
        {
            if (temp[i] == temp[i - 1])
            {
                skip++;
                i--;
            }
        }
    }

    for (int i=start; i < end - skip + 1; i++)
        current[i] = temp[i];

    return end - start - skip + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if (n <= 1)
    {
        cin >> n;
        cout << 0 << '\n';
        exit(0);
    }

    int *origin = new int[n] { 0, };
    int *coor = new int[n] { 0, };
    int *temp = new int[n] { 0, };
    for (int i=0; i < n; i++)
    {
        cin >> origin[i];
        coor[i] = origin[i];
    }
    
    int newLength = mergesort(coor, temp, 0, n - 1, true);
    int find = -1;
    for (int i=0; i < n; i++)
    {
        find = binarysearch(coor, origin[i], 0, newLength - 1);
        cout << find << (i < n - 1 ? ' ' : '\n');
    }
}