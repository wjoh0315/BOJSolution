//https://www.acmicpc.net/problem/11054

/*

동적 계획법을 이용한 풀이 (LIS 응용)


가장 긴 바이토닉 부분 수열의 길이를 구하기 위해
각 루트별 비교를 할 수 있도록 루트 배열 선언

루트 배열은 2차원 배열로 각 인덱스는 두가지의 루트 정보를 담고 있음

루트 정보 1: 증가하는 부분 수열 루트
루트 정보 2: 바이토닉 부분 수열 루트

루트 정보 1은 이전 항들의 값과 비교하여 현재 항의 값이 더 크면서 
가장 긴 루트에 1을 더한 값으로 정의
루트 정보 2는 이전 항들의 값과 비교하여 현재 항의 값이 더 작으면서
증가하는 부분 수열 루트, 바이토닉 부분 수열 루트 중 더 긴 루트에 1을 더한 값으로 정의

이와 같은 과정을 수열 A의 길이만큼 반복해 가장 긴 루트를 구하면 해결

e.g. 
input:
10
1 5 2 1 4 3 4 5 2 1

routes:
1 2 2 1 3 3 4 5 2 1 -> [0]
1 1 3 4 3 4 3 1 6 7 -> [1]

output:
7

*/

#include <iostream>
using namespace std;

int solve(int *a, int length)
{
    int **routes = new int*[length];
    int max = 0;

    for (int i=0; i < length; i++)
    {
        routes[i] = new int[2] { 0, };

        int maxroute_i = 0;
        int maxroute_d = 0;
        for (int j=i-1; j >= 0; j--)
        {
            int tmp_i = routes[j][0];
            int tmp_d = routes[j][0] > routes[j][1]
                ? routes[j][0] : routes[j][1];

            if (a[j] < a[i] && maxroute_i < tmp_i)
                maxroute_i = tmp_i;
            if (a[j] > a[i] && maxroute_d < tmp_d)
                maxroute_d = tmp_d;
        }

        routes[i][0] = maxroute_i + 1;
        routes[i][1] = maxroute_d + 1;

        int tmp_max = routes[i][0] > routes[i][1] ? routes[i][0] : routes[i][1];
        max = tmp_max > max ? tmp_max : max;

        //cout << routes[i][0] << ' ' << routes[i][1] << '\n';
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
