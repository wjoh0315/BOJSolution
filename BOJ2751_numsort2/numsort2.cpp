//https://www.acmicpc.net/problem/2751
#include <iostream>
using namespace std;

void mergesort(int *current, int* temp, int start, int end)
{
    if (start >= end) return;
    int mid = (start + end) / 2;
    mergesort(current, temp, start, mid);
    mergesort(current, temp, mid + 1, end);

    int compare1 = start;
    int compare2 = mid + 1;
    for (int i=start; i < end + 1; i++)
    {
        if (compare2 > end) temp[i] = current[compare1++];
        else if (compare1 > mid) temp[i] = current[compare2++];
        else if (current[compare1] <= current[compare2])
            temp[i] = current[compare1++];
        else
            temp[i] = current[compare2++];
    }

    /*cout << '\n';
    cout << "temp: ";

    for (int i=0; i < 5; i++)
        cout << temp[i] << ' ';

    cout << '\n';
    cout << "current: ";

    for (int i=0; i < 5; i++)
        cout << current[i] << ' ';

    cout << '\n' << '\n';*/

    for (int i=start; i < end + 1; i++)
        current[i] = temp[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int *nums = new int[n];
    int *temparr = new int[n];
    for (int i=0; i < n; i++)
    {
        temparr[i] = 0;
        cin >> nums[i];
    }

    mergesort(nums, temparr, 0, n - 1);
    for (int i=0; i < n; i++)
        cout << nums[i] << '\n';
}