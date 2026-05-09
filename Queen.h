#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
class Queen : public Piece
{
public:
    Queen(int c);
    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8]) override;
};
#endif