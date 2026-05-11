#ifndef KING_H
#define KING_H
#include "Piece.h"
class King : public Piece
{
public:
    King(int c);
    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8]) override;
};
#endif