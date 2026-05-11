#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
class Bishop : public Piece
{
public:
    Bishop(int c);
    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8]) override;
};
#endif