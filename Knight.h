#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
class Knight : public Piece
{
public:
    Knight(int c);
    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8]) override;
};
#endif