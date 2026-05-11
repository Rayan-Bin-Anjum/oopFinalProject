#include "Knight.h"
#include <cmath>
Knight::Knight(int c) : Piece(c, ' ')
{
    if (c == WHITE)
        symbol = 'N';
    else
        symbol = 'n';
}
bool Knight::isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8])
{
    int dr = abs(toRow - fromRow);
    int dc = abs(toCol - fromCol);
    if ((dr == 2 && dc == 1) || (dr == 1 && dc == 2))
    {
        if (board[toRow][toCol] == nullptr)
            return true;
        if (board[toRow][toCol]->getColor() != color)
            return true;
    }
    return false;
}