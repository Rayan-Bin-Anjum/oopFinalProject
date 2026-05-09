#include "Pawn.h"
#include <cmath>
Pawn::Pawn(int c) : Piece(c, ' ')
{
    if (c == WHITE)
        symbol = 'P';
    else
        symbol = 'p';
}
bool Pawn::isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8])
{
    int direction;
    int startRow;
    if (color == WHITE)
    {
        direction = -1;
        startRow = 6;
    }
    else
    {
        direction = 1;
        startRow = 1;
    }
    if (fromCol == toCol && toRow == fromRow + direction && board[toRow][toCol] == nullptr)
        return true;
    if (fromCol == toCol && fromRow == startRow && toRow == fromRow + 2 * direction)
    {
        if (board[fromRow + direction][fromCol] == nullptr && board[toRow][toCol] == nullptr)
            return true;
    }
    if (abs(toCol - fromCol) == 1 && toRow == fromRow + direction && board[toRow][toCol] != nullptr)
    {
        if (board[toRow][toCol]->getColor() != color)
            return true;
    }
    return false;
}