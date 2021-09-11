//https://www.acmicpc.net/problem/11053

/*

동적 계획법을 이용한 풀이 (LIS)


가장 긴 증가하는 부분 수열의 길이를 구하기 위해
각 루트를 비교할 수 있도록 루트 배열을 선언

최적 루트를 선정하려면 이전 값들과 비교해 현재 값과 작으면서
가장 긴 루트를 선정해 현재 값과 이어붙이면 됨

이와 같은 과정을 수열의 길이만큼 반복하여 루트 배열을 만들고
루트 배열에서 가장 큰 값이 가장 긴 증가하는 부분 수열의 길이

*/

#include <iostream>
using namespace std;

int solve(int *a, int length)
{
    int *routes = new int[length] { 0, };
    int max = 0;

    for (int i=0; i < length; i++)
    {
        int maxroute = 0;
        for (int j=i-1; j >= 0; j--)
        {
            if (a[j] < a[i] && maxroute < routes[j])
                maxroute = routes[j];
        }
        
        routes[i] = maxroute + 1;
        max = routes[i] > max ? routes[i] : max;
    }

    return max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i=0; i < n; i++)
        cin >> arr[i];

    cout << solve(arr, n) << '\n';
}