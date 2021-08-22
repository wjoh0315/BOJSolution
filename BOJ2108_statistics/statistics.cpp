//https://www.acmicpc.net/problem/2108
#include <iostream>
#include <cmath>
using namespace std;

int countingsort(int *current, int* countingreturn, int length, int min, int max)
{
    int *countingarr = new int[max-min+1] { 0, };
    int *sortarr = new int[length];
    for (int i=0; i < length; i++)
        countingarr[current[i] - min]++;

    int frequencymax = 0;
    for (int i=0; i < max-min+1; i++)
    {
        if (countingarr[i] > frequencymax)
            frequencymax = countingarr[i];
        countingreturn[i] = countingarr[i];
        
        if (i > 0)
            countingarr[i] += countingarr[i - 1];
    }

    for (int i=length - 1; i >= 0; i--)
        sortarr[--countingarr[current[i] - min]] = current[i];
    
    for (int i=0; i < length; i++)
        current[i] = sortarr[i];

    return frequencymax;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int sum = 0;
    int max = 0;
    int min = 0;
    int *nums = new int[n];
    bool start = false;

    for (int i=0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];

        if (nums[i] > max || !start)
            max = nums[i];
        if (nums[i] < min || !start)
            min = nums[i];

        start = true;
    }

    int curindex = 0;
    int amount = 0;
    int *countingarr = new int[max-min+1] { 0, };
    int maxcount = countingsort(nums, countingarr, n, min, max);
    for (int i=0; i < max-min+1; i++)
    {
        if (countingarr[i] == maxcount)
        {
            curindex = i + min;
            amount++;
        }
        if (amount >= 2)
            break;
    }

    cout << round((double)sum / n) << '\n';
    cout << nums[n / 2] << '\n';
    cout << curindex << '\n';
    cout << max - min << '\n';
}