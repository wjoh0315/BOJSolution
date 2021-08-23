//https://www.acmicpc.net/problem/1181
#include <iostream>
#include <string>
using namespace std;

void mergewordsort(string *current, string *temp, int start, int end)
{
    if (start >= end) return;
    int mid = (start + end) / 2;
    mergewordsort(current, temp, start, mid);
    mergewordsort(current, temp, mid + 1, end);

    int compare1 = start;
    int compare2 = mid + 1;
    for (int i=start; i < end + 1; i++)
    {
        if (compare1 > mid)
        { 
            temp[i] = current[compare2++];
            continue;
        }
        else if (compare2 > end) 
        {
            temp[i] = current[compare1++];
            continue;
        }
        else if (current[compare1].length() < current[compare2].length())
        {
            temp[i] = current[compare1++];
            continue;
        }
        else if (current[compare1].length() == current[compare2].length())
        {
            bool skip = false;
            for (int j=0; j < current[compare1].length(); j++)
            {
                if (current[compare1][j] < current[compare2][j])
                {
                    temp[i] = current[compare1++];
                    skip = true;
                    break;
                }
                else if (current[compare1][j] > current[compare2][j])
                {
                    temp[i] = current[compare2++];
                    skip = true;
                    break;
                }
            }
            
            if (skip)
                continue;
        }

        temp[i] = current[compare2++];
    }
    
    for (int i=start; i < end + 1; i++)
        current[i] = temp[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string *words = new string[n] { "", };
    string *temp = new string[n] { "", };
    for (int i=0; i < n; i++)
        cin >> words[i];

    mergewordsort(words, temp, 0, n - 1);
    for (int i=0; i < n; i++)
    {
        if (i - 1 >= 0)
        {
            if (words[i - 1] == words[i])
                continue;
        }
        cout << words[i] << '\n';
    }
}