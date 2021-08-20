//https://www.acmicpc.net/problem/2447
#include <iostream>
using namespace std;

void starbox(int side, int x, int y, bool isEmpty, char **starmat)
{
    if (side == 3)
    {
        for (int i=0; i < 3; i++)
        {
            for (int j=0; j < 3; j++)
            {
                starmat[y + i][x + j] = (i != 1 || j != 1) 
                    && !isEmpty ? '*' : ' ';
            }
        }
    }
    else
    {
        for (int i=0; i < 3; i++)
        {
            for (int j=0; j < 3; j++)
            {
                starbox(side / 3, x + j * (side / 3), y + i * (side / 3), 
                    !isEmpty ? i == 1 && j == 1 : isEmpty, starmat);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int in;
    cin >> in;

    char **starmat;
    starmat = new char*[in];
    for (int i=0; i < in; i++)
        starmat[i] = new char[in] { ' ', };


    starbox(in, 0, 0, false, starmat);
    for (int i=0; i < in; i++)
    {
        for (int j=0; j < in; j++)
            cout << starmat[i][j];
        cout << '\n';
    }

    for (int i=0; i < in; i++)
        delete[] starmat[i];
    delete[] starmat;
}