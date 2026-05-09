#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
class Pawn : public Piece
{
public:
    Pawn(int c);
    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8]) override;
};
#endif