//https://www.acmicpc.net/problem/1427
#include <iostream>
#include <string>
using namespace std;

void bubblesort(string *current, int length)
{
    for (int i=length - 1; i > 0; i--)
    {
        for (int j=0; j < i; j++)
        {
            if ((*current)[j] - '0' < (*current)[j + 1] - '0')
            {
                char temp = (*current)[j];
                (*current)[j] = (*current)[j + 1];
                (*current)[j + 1] = temp;
            }
            else if (j + 2 < i)
            {
                if ((*current)[j] - '0' < (*current)[j + 2] - '0')
                {
                    char temp = (*current)[j];
                    (*current)[j] = (*current)[j + 2];
                    (*current)[j + 2] = temp;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string in;
    cin >> in;

    bubblesort(&in, in.length());
    cout << in << '\n';
}