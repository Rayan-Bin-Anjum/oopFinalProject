#include "Piece.h"
Piece::Piece(int c, char s) : color(c), symbol(s) {};
int Piece::getColor()
{
	return color;
}
char Piece::getSymbol()
{
	return symbol;
}
Piece::~Piece() {};