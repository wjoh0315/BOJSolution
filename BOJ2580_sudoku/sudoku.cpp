//https://www.acmicpc.net/problem/2580
#include <iostream>
using namespace std;

bool scan(int board[9][9], int pre[3][9], int current)
{
    int i = current;
    //cout << i << " enter" << '\n';

    for (int j=0; j < 9; j++)
    {
        // horizontal scan
        if (board[i / 9][j] != 0)
        {
            if (pre[0][board[i / 9 + j / 9][j] - 1] == 1)
            {
                //cout << i << " return: h scan, " << board[i / 9 + j / 9][j] - 1  << '\n';
                return false;
            }
            pre[0][board[i / 9 + j / 9][j] - 1] = 1;
        }
            
        // vertical scan
        if (board[j][i % 9] != 0)
        {
            if (pre[1][board[j][i % 9] - 1] == 1)
            {
                //cout << i << " return: v scan, " << board[j][i % 9] - 1 << '\n';
                return false;
            }
            pre[1][board[j][i % 9] - 1] = 1;
        }

        // box scan
        if (board[i / 9 - i / 9 % 3 + j / 3][i % 9 - i % 9 % 3 + j % 3] != 0)
        {
            if (pre[2][board[i / 9 - i / 9 % 3 + j / 3][i % 9 - i % 9 % 3 + j % 3] - 1] == 1)
            {
                //cout << i << " return: b scan, " << board[i / 9 - i / 9 % 3 + j / 3][i % 9 - i % 9 % 3 + j % 3] - 1 << '\n';
                return false;
            }
            pre[2][board[i / 9 - i / 9 % 3 + j / 3][i % 9 - i % 9 % 3 + j % 3] - 1] = 1;
        }
        
        /*cout << j << "  ";
        for (int k=0; k < 9; k++)
            cout << pre[2][k] << ' ';

        cout << '\n';*/
    }

    return true;
}

bool sudoku(int board[9][9], int start)
{
    //cout << '\n';

    for (int i=start; i < 81; i++)
    {
        if (board[i / 9][i % 9] == 0)
        {
            for (int j=0; j < 9; j++)
            {
                int pre[3][9] = { { 0, }, };
                bool success = scan(board, pre, i);
                if (!success)
                {
                    board[i / 9][i % 9] = 0;
                    return false;
                }

                if (pre[0][j] == 0 
                && pre[1][j] == 0 && pre[2][j] == 0)
                {
                    board[i / 9][i % 9] = j + 1;
                    if (sudoku(board, i + 1) == true)
                        return true;
                }
            }

            board[i / 9][i % 9] = 0;
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sudokub[9][9];
    for (int i=0; i < 81; i++)
        cin >> sudokub[i / 9][i % 9];

    sudoku(sudokub, 0);
    //cout << '\n';

    for (int i=0; i < 81; i++)
    {
        if (i >= 9 && i % 9 == 0)
            cout << '\n';
        cout << sudokub[i / 9][i % 9] << ' ';
    }
}