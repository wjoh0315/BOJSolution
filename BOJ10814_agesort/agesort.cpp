//https://www.acmicpc.net/problem/10814
#include <iostream>
using namespace std;

void mergeagesort(int *current_ages, string *current_names, 
int *temp_ages, string *temp_names, int start, int end)
{
    if (start >= end) return;
    int mid = (start + end) / 2;
    mergeagesort(current_ages, current_names, temp_ages, temp_names, start, mid);
    mergeagesort(current_ages, current_names, temp_ages, temp_names, mid + 1, end);

    int compare1 = start;
    int compare2 = mid + 1;
    for (int i=start; i < end + 1; i++)
    {
        if (compare1 > mid)
        { 
            temp_ages[i] = current_ages[compare2];
            temp_names[i] = current_names[compare2];
            compare2++;
        }
        else if (compare2 > end) 
        {
            temp_ages[i] = current_ages[compare1];
            temp_names[i] = current_names[compare1];
            compare1++;
        }
        else if (current_ages[compare1] <= current_ages[compare2])
        {
            temp_ages[i] = current_ages[compare1];
            temp_names[i] = current_names[compare1];
            compare1++;
        }
        else 
        {
            temp_ages[i] = current_ages[compare2];
            temp_names[i] = current_names[compare2];
            compare2++;
        }
    }
    
    for (int i=start; i < end + 1; i++)
    {
        current_ages[i] = temp_ages[i];
        current_names[i] = temp_names[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int *ages = new int[n] { 0, };
    int *temp_ages = new int[n] { 0, };
    string *names = new string[n] { "", };
    string *temp_names = new string[n] { "" };
    for (int i=0; i < n; i++)
    {
        cin >> ages[i];
        cin >> names[i];
    }

    mergeagesort(ages, names, temp_ages, temp_names, 0, n - 1);
    for (int i=0; i < n; i++)
    {
        cout << ages[i] << ' ';
        cout << names[i] << '\n';
    }
}