//https://www.acmicpc.net/problem/2156

/* 

동적 계획법을 이용한 풀이

와인을 최대로 마시는 루트를 찾기 위해서는
여러 루트를 비교할 수 있는 루트 배열이 필요
루트 배열은 2차원 배열로,
각 인덱스에서의 두가지 최적 루트 정보를 저장

루트 정보 1: 연속해서 마시는 경우
루트 정보 2: 뛰어넘어 마시는 경우

뛰어넘어 마시는 경우는 i - 2번째 와인, i - 3번째 와인에서 
현재 와인으로 뛰어넘어 마심 
(2잔씩, 3잔씩 뛰어넘으면 모든 와인을 영향권에 둘 수 있음
11 = 3 + 3 + 2, 13 = 3 + 3 + 3 + 2 + 2, 7 = 3 + 2 + 2 등)

따라서, 와인 배열 wines에서 루트 배열의 점화식은 다음과 같음 (i > 1)

routes[0][0] = wines[0] -> 연속해서 마시는 루트
routes[0][1] = 0 -> 뛰어넘어 마시는 루트
routes[1][0] = wines[0] + wines[1] -> 두 와인을 연속해서 마시는 루트
routes[1][1] = wines[1] -> 두번째 와인으로 뛰어넘어 마시는 루트

routes[i][0] = wines[i] + routes[i - 1][1] -> 뛰어넘어 마신 루트 지점에서 연속으로 마시는 루트
(연속해서 마신 루트 지점에서 또 연속해서 마시면 3잔을 모두 마시게 되어 조건 위반)
i < 3 인 경우
routes[i][1] = wines[i] + MAX(routes[i - 2][0], routes[i - 2][1])
ㄴ> 2잔 뛰어넘어 와인을 마시는 루트 (2잔 이전 와인의 두 루트를 비교해 최대로 마시는 루트로 저장)
i >= 3 인 경우
routes[i][1] = wines[i] + MAX(routes[i - 2][0], routes[i - 2][1], routes[i - 3][0], routes[i - 3][1])
ㄴ> 2잔 뛰어넘어 와인을 마시는 루트와 3잔 뛰어넘어 와인을 마시는 루트를 비교해 최대로 마시는 루트로 저장

*/

#include <iostream>
using namespace std;

int getmax(int a, int b)
{
    return a>b?a:b;
}

int wine(int *wines, int length)
{
    int **routes = new int*[length];
    
    routes[0] = new int[2];
    routes[0][0] = wines[0];
    routes[0][1] = 0;
    if (length == 1)
        return routes[0][0];

    routes[1] = new int[2];
    routes[1][0] = wines[0] + wines[1];
    routes[1][1] = wines[1];
    if (length == 2)
        return routes[1][0];

    for (int i=2; i < length; i++)
    {
        routes[i] = new int[2];
        routes[i][0] = wines[i] + routes[i - 1][1];
        if (i < 3)
            routes[i][1] = wines[i] 
                + getmax(routes[i - 2][0], routes[i - 2][1]);
        else
            routes[i][1] = wines[i] + getmax(
                getmax(routes[i - 2][0], routes[i - 2][1]),
                getmax(routes[i - 3][0], routes[i - 3][1])
            );
    }

    return getmax(
        getmax(routes[length - 2][0], routes[length - 2][1]), 
        getmax(routes[length - 1][0], routes[length - 1][1])
    );
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int *winesarr = new int[n];
    for (int i=0; i < n; i++)
        cin >> winesarr[i];

    cout << wine(winesarr, n) << '\n';
}