#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
class Rook : public Piece
{
public:
    Rook(int c);
    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8]) override;
};
#endif