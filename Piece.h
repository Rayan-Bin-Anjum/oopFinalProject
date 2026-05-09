#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>
using namespace std;
const int WHITE = 1;
const int BLACK = 2;
const int EMPTY = 0;
class Piece
{
protected:
    int color;
    char symbol;
public:
    Piece(int c, char s);
    int getColor();
    char getSymbol();
    virtual bool isValidMove(int fromRow, int fromCol, int toRow, int toCol, Piece* board[8][8]) = 0;
    virtual ~Piece();
};
#endif