//https://www.acmicpc.net/problem/2750
#include <iostream>
using namespace std;

void bubblesort(int *current, int length)
{
    for (int i=length - 1; i > 0; i--)
    {
        for (int j=0; j < i + 1; j++)
        {
            if (j + 1 < length)
            {
                if (current[j] > current[j + 1])
                {
                    int temp = current[j + 1];
                    current[j + 1] = current[j];
                    current[j] = temp;
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *nums = new int[n];
    for (int i=0; i < n; i++)
        cin >> nums[i];

    bubblesort(nums, n);
    for (int i=0; i < n; i++)
        cout << nums[i] << '\n';
}