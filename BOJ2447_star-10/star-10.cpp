#include <iostream>
using namespace std;

void starbox(int side, 
int x, int y, char **starmat)
{
    if (side == 3)
    {
        for (int i=0; i < 3; i++)
        {
            for (int j=0; j < 3; j++)
            {
                if (i != 1 || j != 1)
                    starmat[y + i][x + j] = '*';
                else
                    starmat[y + i][x + j] = ' ';
            }
        }
    }
    else
    {
        for (int i=0; i < 3; i++)
        {
            for (int j=0; j < 3; j++)
            {
                if (i != 1 || j != 1)
                    starbox(side / 3, x + j * (side / 3), y + i * (side / 3), starmat);
            }
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int in;
    cin >> in;

    char **starmat;
    starmat = new char*[in];
    for (int i=0; i < in; i++)
        starmat[i] = new char[in] { ' ', };

    starbox(in, 0, 0, starmat);
    for (int i=0; i < in; i++)
    {
        cout << starmat[i] << '\n';
    }

    for (int i=0; i < in; i++)
        delete[] starmat[i];
    delete[] starmat;
}