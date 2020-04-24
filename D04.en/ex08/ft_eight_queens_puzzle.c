#include <stdlib.h>
#include <unistd.h>

int g_possibilities;

int check_squares (int board[8][8], int row, int square)
{
    int ch;

    ch = 0;
    while (ch < row)
    {
        if (board[ch][square] == 1)
            return 0;
        ch++;
    }
    ch = 0;
    while (row - ch >= 0 && square + ch < 8)
    {
        if (board[row - ch][square + ch] == 1)
            return 0;
        ch++;
    }
    ch = 0;
    while (row - ch >= 0 && square - ch >= 0)
    {
        if (board[row - ch][square - ch] == 1)
            return 0;
        ch++;
    }
    return 1;
}

int queen_rows (int board[8][8], int row)
{
    int square;

    square = 0;
    while (square < 8)
    {
        if (check_squares(board, row, square))
        {
            board[row][square] = 1;
            if (row == 7)
                g_possibilities++;
            else
                queen_rows(board, row + 1);
        }
        board[row][square] = 0;
        square++;
    }     
    return g_possibilities;
}

int ft_eight_queens_puzzle(void)
{
    int board[8][8];
    int row;
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 8)
    {   
        while (j < 8)
        {
            board[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
    row = 0;
    return queen_rows(board, row);
}