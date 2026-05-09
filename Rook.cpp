#include "Rook.h"
Rook::Rook(int c) : Piece(c, ' ')
{
    if (c == WHITE)
        symbol = 'R';
    else
        symbol = 'r';
}
bool Rook::isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8])
{
    if (fromRow != toRow && fromCol != toCol)
        return false;
    if (fromRow == toRow)
    {
        int step;
        if (toCol > fromCol)
            step = 1;
        else
            step = -1;
        for (int c = fromCol + step; c != toCol; c += step)
            if (board[fromRow][c] != nullptr)
                return false;
    }
    else
    {
        int step;
        if (toRow > fromRow)
            step = 1;
        else
            step = -1;
        for (int r = fromRow + step; r != toRow; r += step)
            if (board[r][fromCol] != nullptr)
                return false;
    }
    if (board[toRow][toCol] == nullptr)
        return true;
    if (board[toRow][toCol]->getColor() != color)
        return true;
    return false;
}