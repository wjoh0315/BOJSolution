//https://www.acmicpc.net/problem/14889
#include <iostream>
using namespace std;

void getminf(int *min, int **team, int *temp, int n, int newi, int cur, int team1, int team2)
{
    if (cur > n / 2)
    {
        int result = 0;
        int start = 0;
        for (int i=0; i < n; i++)
        {
            if (temp[i] == 1)
                continue;
            
            bool set = false;
            for (int j=start; j < n; j++)
            {
                if (i == j)
                    continue;

                if (temp[j] == 0)
                {
                    if (!set)
                        start = j + 1;
                    set = true;
                    result += team[i][j] + team[j][i];
                }
            }

            /*for (int j=0; j < n; j++)
                cout << temp[j] << ' ';

            cout << '\n';*/
        }

        team2 += result;
        //cout << abs(team1 - team2) << "  " << team1 << ' ' << team2 << '\n';
        if (abs(team1 - team2) < *min)
            *min = abs(team1 - team2);
    }
    else
    {
        for (int i=newi; i < n; i++)
        {
            if (temp[i] == 1)
                continue;

            int result = 0; 
            for (int j=0; j < n; j++)
            {
                if (i == j)
                    continue;

                if (temp[j] == 1)
                    result += team[i][j] + team[j][i];
            }

            /*for (int j=0; j < n; j++)
                cout << temp[j] << ' ';

            cout << '\n';*/

            temp[i] = 1;
            getminf(min, team, temp, n, i + 1, cur + 1, team1 + result, team2);
            temp[i] = 0;
        }
    }
    
}

int getmin(int **team, int n)
{
    int min = 100;
    int *temp = new int[n] { 0, };
    getminf(&min, team, temp, n, 0, 1, 0, 0);
    return min;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int **team = new int*[n];
    for (int i=0; i < n * n; i++)
    {
        if (i % n == 0)
            team[i / n] = new int[n];
        cin >> team[i / n][i % n];
    }

    cout << getmin(team, n) << '\n';
}