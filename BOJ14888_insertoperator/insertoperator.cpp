//https://www.acmicpc.net/problem/14888
#include <iostream>
using namespace std;

void getminmax(int *min, int *max, int n, int *nums, int operators[4], int result, int cur)
{
    if (cur >= n)
    {
        if (result > *max)
            *max = result;
        if (result < *min)
            *min = result;
        return;
    }

    int temp[4] = { 0, };
    for (int i=0; i < 4; i++)
        temp[i] = operators[i];

    int tempresult = result;
    for (int i=0; i < 4; i++)
    {
        if (temp[i] <= 0)
            continue;

        temp[i]--;
        if (i == 0)
            tempresult = result + nums[cur];
        else if (i == 1)
            tempresult = result - nums[cur];
        else if (i == 2)
            tempresult = result * nums[cur];
        else if (i == 3)
            tempresult = result / nums[cur];

        getminmax(min, max, n, nums, temp, tempresult, cur + 1);
        temp[i]++;
    }
}

void minmax(int *min, int *max, int n, int *nums, int operators[4])
{
    getminmax(min, max, n, nums, operators, nums[0], 1);
}

int main()
{
    int n;
    cin >> n;
    
    int *nums = new int[n] { 0, };
    int operators[4] = { 0, };
    int min = 100000000;
    int max = -100000000;
    for (int i=0; i < n; i++)
        cin >> nums[i];
    for (int i=0; i < 4; i++)
        cin >> operators[i];
    
    minmax(&min, &max, n, nums, operators);

    cout << max << '\n';
    cout << min << '\n';
}