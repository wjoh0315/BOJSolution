//https://www.acmicpc.net/problem/1436
#include <iostream>
#include <string>
using namespace std;

string movienum(int index)
{
    string currentS = "666";
    string add = "666";
    string make = "";
    string newAdd = "";

    int digit = 0;
    int viindex = 1;

    if (index > 1)
    {
        for (int i=1; i < index; i++)
        {
            currentS = to_string(viindex);
            digit = currentS.length() + 3;

            //cout << viindex << ' ' << i << '\n';
            if (currentS.back() == '6')
            {
                add = "66";
                make = "9";   
                
                for (int j=currentS.length() - 2; j >= 0; j--)
                {
                    if (currentS[j] == '6')
                    {
                        add.pop_back();
                        make += "9";
                    }
                    else
                        break;
                }
                currentS += add;

                for (int j=0; j < stoi(make) + 1; j++)
                {
                    if (i >= index)
                    {
                        //cout << currentS << ' ' << i << " end" << '\n';
                        break;
                    } 

                    newAdd = "";
                    for (int k=0; k < make.length() - to_string(j).length(); k++)
                        newAdd += "0";

                    newAdd += to_string(j);
                    currentS = currentS.substr(0, digit - make.length()) + newAdd;
                    i++;
                    //cout << currentS << ' ' << i << '\n';
                }
                i--;
            }
            else
            {
                currentS = currentS.substr(0, digit - 3) + "666";
            }
            
            viindex++;
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