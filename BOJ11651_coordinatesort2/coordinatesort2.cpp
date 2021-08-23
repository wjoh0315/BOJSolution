//https://www.acmicpc.net/problem/11651
#include <iostream>
using namespace std;

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
        else if (current[compare1][1] < current[compare2][1])
        {
            temp[i][0] = current[compare1][0];
            temp[i][1] = current[compare1][1];
            compare1++;
        }
        else if (current[compare1][1] == current[compare2][1]
            && current[compare1][0] < current[compare2][0])
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