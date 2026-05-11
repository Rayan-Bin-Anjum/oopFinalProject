#include "Bishop.h"
#include <cmath>
Bishop::Bishop(int c) : Piece(c, ' ')
{
    if (c == WHITE)
        symbol = 'B';
    else
        symbol = 'b';
}
bool Bishop::isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8])
{
    int dr = abs(toRow - fromRow);
    int dc = abs(toCol - fromCol);
    if (dr != dc || dr == 0)
        return false;
    int stepR;
    int stepC;
    if (toRow > fromRow)
        stepR = 1;
    else
        stepR = -1;
    if (toCol > fromCol)
        stepC = 1;
    else
        stepC = -1;
    int r = fromRow + stepR;
    int c = fromCol + stepC;
    while (r != toRow && c != toCol)
    {
        if (board[r][c] != nullptr)
            return false;
        r += stepR;
        c += stepC;
    }
    if (board[toRow][toCol] == nullptr)
        return true;
    if (board[toRow][toCol]->getColor() != color)
        return true;
    return false;
}
