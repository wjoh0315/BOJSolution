//https://www.acmicpc.net/problem/7568
#include <iostream>
using namespace std;

int *dungchirank(int **dungchis, int length)
{
    int *rank = new int[length] { 0, };
    int weight, height;
    for (int i=0; i < length; i++)
    {
        weight = dungchis[i][0];
        height = dungchis[i][1];
        rank[i] = length;

        for (int j=0; j < length; j++)
        {
            if (j != i)
            {
                if (weight >= dungchis[j][0] || height >= dungchis[j][1])
                    rank[i]--; // rankup
            }
        }
    }

    return rank;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int in;
    cin >> in;

    int **dungchis = new int*[in];
    for (int i=0; i < in; i++)
    {
        dungchis[i] = new int[2] { 0, };
        cin >> dungchis[i][0];
        cin >> dungchis[i][1];
    }

    int *dungchirankout;
    dungchirankout = dungchirank(dungchis, in);
    for (int i=0; i < in; i++)
        cout << dungchirankout[i] << (i != in-1 ? ' ' : '\n');

    for (int i=0; i < in; i++)
        delete[] dungchis[i];
    delete[] dungchis;
    delete[] dungchirankout;
}