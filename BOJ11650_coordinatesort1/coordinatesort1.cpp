//https://www.acmicpc.net/problem/11650
#include <iostream>
using namespace std;

/*void coordinatesort(int **current, int length)
{
    for (int i=length - 1; i > 0; i--)
    {
        for (int j=0; j < i; j++)
        {
            if (current[j][0] > current[j + 1][0])
            {
                int temp[2];
                temp[0] = current[j][0];
                temp[1] = current[j][1];

                current[j][0] = current[j + 1][0];
                current[j][1] = current[j + 1][1];
                current[j + 1][0] = temp[0];
                current[j + 1][1] = temp[1];
            }
            if (current[j][0] == current[j + 1][0] 
                && current[j][1] > current[j + 1][1])
            {
                int temp[2];
                temp[0] = current[j][0];
                temp[1] = current[j][1];

                current[j][0] = current[j + 1][0];
                current[j][1] = current[j + 1][1];
                current[j + 1][0] = temp[0];
                current[j + 1][1] = temp[1];
            }
            if (j + 2 < i)
            {
                if (current[j][0] > current[j + 2][0])
                {
                    int temp[2];
                    temp[0] = current[j][0];
                    temp[1] = current[j][1];

                    current[j][0] = current[j + 2][0];
                    current[j][1] = current[j + 2][1];
                    current[j + 2][0] = temp[0];
                    current[j + 2][1] = temp[1];
                }
            }
        }
    }
}*/

void mergecoordinatesort(int **current, int **temp, int start, int end)
{
    if (start >= end) return;
    int mid = (start + end) / 2;
    mergecoordinatesort(current, temp, start, mid);
    mergecoordinatesort(current, temp, mid + 1, end);

    int compare1 = start;
    int compare2 = mid + 1;
    for (int i=start; i < end + 1; i++)
    {
        if (compare1 > mid)
        {
             temp[i][0] = current[compare2][0];
             temp[i][1] = current[compare2][1];
             compare2++;
        }
        else if (compare2 > end) 
        {
            temp[i][0] = current[compare1][0];
            temp[i][1] = current[compare1][1];
            compare1++;
        }
        else if (current[compare1][0] < current[compare2][0])
        {
            temp[i][0] = current[compare1][0];
            temp[i][1] = current[compare1][1];
            compare1++;
        }
        else if (current[compare1][0] == current[compare2][0]
            && current[compare1][1] < current[compare2][1])
        {
            temp[i][0] = current[compare1][0];
            temp[i][1] = current[compare1][1];
            compare1++;
        }
        else 
        {
            temp[i][0] = current[compare2][0];
            temp[i][1] = current[compare2][1];
            compare2++;
        }
    }
    
    for (int i=start; i < end + 1; i++)
    {
        current[i][0] = temp[i][0];
        current[i][1] = temp[i][1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int **coordinates = new int*[n];
    int **temp = new int*[n];
    for (int i=0; i < n; i++)
    {
        coordinates[i] = new int[2] { 0, };
        temp[i] = new int[2] { 0, };
        cin >> coordinates[i][0];
        cin >> coordinates[i][1];
    }

    mergecoordinatesort(coordinates, temp, 0, n - 1);
    for (int i=0; i < n; i++)
    {
        cout << coordinates[i][0] << ' ';
        cout << coordinates[i][1] << '\n';
        delete[] coordinates[i];
    }
    delete[] coordinates;
}