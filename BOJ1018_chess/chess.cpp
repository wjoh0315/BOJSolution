#include <iostream>
using namespace std;

char switchWB(char WB)
{
    if (WB == 'W')
        return 'B';
    else if (WB == 'B')
        return 'W';
    else
        return '\0';
}

int chessscan(char **board, int Nstart, int Nend, 
int Mstart, int Mend)
{
    int count1 = 0;
    int count2 = 0;
    char pattern1 = 'W';
    char pattern2 = 'B';

    for (int i=Nstart; i < Nend + 1; i++)
    {
        for (int j=Mstart; j < Mend + 1; j++)
        {
            //cout << (board[i][j] != pattern1) << ' ' << (board[i][j] != pattern2) << '\n';
            if (board[i][j] != pattern1)
                count1++;
            if(board[i][j] != pattern2)
                count2++;

            pattern1 = switchWB(pattern1);
            pattern2 = switchWB(pattern2);
        }

        pattern1 = switchWB(pattern1);
        pattern2 = switchWB(pattern2);
    }
    //cout << count1 << ' ' << count2 << '\n';
    return count1 > count2 ? count2 : count1; 
}

int chesspaint(char **board, int width, int height)
{
    int preCount = 0;
    bool isStart = false;

    if (width == 8 && height == 8)
        preCount = chessscan(board, 0, 7, 0, 7);
    else
    {
        for (int i=0; i < height - 7; i++)
        {
            for (int j=0; j < width - 7; j++)
            {
                int scan = chessscan(board, i, i + 7, j, j + 7);
                if ((scan < preCount && isStart) || !isStart)
                    preCount = scan;
                isStart = true;
            }
        }
    }

    return preCount;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    char **chessboard = new char*[N];
    for (int i=0; i < N; i++)
    {
        chessboard[i] = new char[M];
        cin >> chessboard[i];
    }

    cout << chesspaint(chessboard, M, N) << '\n';

    for (int i=0; i < N; i++)
        delete[] chessboard[i];
    delete[] chessboard;
}