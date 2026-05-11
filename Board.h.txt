#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"
class Board
{
private:
    Piece* grid[8][8];
public:
    Board();
    ~Board();
    void setupPieces();
    void display();
    Piece* getPiece(int r, int c);
    bool movePiece(int fromRow, int fromCol, int toRow, int toCol);
    bool kingAlive(int color);
};
#endif