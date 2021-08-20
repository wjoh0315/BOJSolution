//https://www.acmicpc.net/problem/2798
#include <iostream>
#include <sstream>
using namespace std;

int getsum(int *currentCards, int length, int max)
{
    int bsum = 0;
    for (int i=0; i < length; i++)
    {
        for (int j=0; j < length; j++)
        {
            if (j != i)
            {
                for (int k=0; k < length; k++)
                {
                    if (k != j && k != i)
                    {
                        int sum = currentCards[i] + currentCards[j] + currentCards[k];
                        if (max == sum)
                            return max;
                        else if (max - sum >= 0 && max - sum < max - bsum)
                            bsum = sum;
                    }
                }
            }
        }
    }

    return bsum;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int *cards = new int[n];
    for (int i=0; i < n; i++)
        cin >> cards[i];

    cout << getsum(cards, n, m);
    delete[] cards;
}