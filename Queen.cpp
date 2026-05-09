#include "Queen.h"
#include <cmath>
Queen::Queen(int c) : Piece(c, ' ')
{
    if (c == WHITE)
        symbol = 'Q';
    else
        symbol = 'q';
}
bool Queen::isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8])
{
    int dr = abs(toRow - fromRow);
    int dc = abs(toCol - fromCol);
    bool straight = (fromRow == toRow || fromCol == toCol);
    bool diagonal = (dr == dc && dr != 0);
    if (straight == false && diagonal == false)
        return false;
    int stepR = 0;
    int stepC = 0;
    if (toRow > fromRow)
        stepR = 1;
    else if (toRow < fromRow)
        stepR = -1;
    if (toCol > fromCol)
        stepC = 1;
    else if (toCol < fromCol)
        stepC = -1;
    int r = fromRow + stepR;
    int c = fromCol + stepC;
    while (r != toRow || c != toCol)
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