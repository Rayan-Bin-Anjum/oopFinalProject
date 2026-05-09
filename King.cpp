#include "King.h"
#include <cmath>
King::King(int c) : Piece(c, ' ')
{
    if (c == WHITE)
        symbol = 'K';
    else
        symbol = 'k';
}
bool King::isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8])
{
    int dr = abs(toRow - fromRow);
    int dc = abs(toCol - fromCol);
    if (dr <= 1 && dc <= 1)
    {
        if (board[toRow][toCol] == nullptr)
            return true;
        if (board[toRow][toCol]->getColor() != color)
            return true;
    }
    return false;
}