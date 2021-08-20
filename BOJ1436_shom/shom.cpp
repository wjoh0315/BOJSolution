//https://www.acmicpc.net/problem/1436
#include <iostream>
#include <string>
using namespace std;

string movienum(int index)
{
    string currentS = "666";
    int digit = 0;
    int viindex = 1;
    if (index > 1)
    {
        for (int i=1; i < index; i++)
        {
            currentS = to_string(viindex);
            digit = currentS.length() + 3;

            int pos6 = currentS.find('6');
            cout << viindex << ' ' << i << '\n';
            if (pos6 != -1)
            {
                string add = "666";
                string make = "";
                int diff = currentS.length() - pos6 - 1;
                digit -= diff;
                for (int j=pos6; j < currentS.length(); j++)
                {
                    add.pop_back();
                    currentS[j] = '6';
                    make += "9";
                }
                currentS += add;

                for (int j=0; j < stoi(make) + 1; j++)
                {
                    string newAdd = "";
                    for (int k=0; k < diff - 1; k++)
                        newAdd += "0";

                    newAdd += to_string(j);
                    currentS = currentS.substr(0, digit - 1) + newAdd;
                    i++;

                    if (i >= index - 2)
                        break; 
                }
                
                viindex++;
            }
            else
            {
                currentS = currentS.substr(0, digit - 3) + "666";
                viindex++;
            }
        }
    }

    return currentS;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int in;
    cin >> in;

    cout << movienum(in) << '\n';
}