#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
Board::Board()
{
	for (int r = 0; r < 8; r++)
		for (int c = 0; c < 8; c++)
			grid[r][c] = nullptr;
	setupPieces();
}
Board::~Board()
{
	for (int r = 0; r < 8; r++)
		for (int c = 0; c < 8; c++)
			if (grid[r][c] != nullptr)
				delete grid[r][c];
}
void Board::setupPieces()
{
	grid[0][0] = new Rook(BLACK);
	grid[0][1] = new Knight(BLACK);
	grid[0][2] = new Bishop(BLACK);
	grid[0][3] = new Queen(BLACK);
	grid[0][4] = new King(BLACK);
	grid[0][5] = new Bishop(BLACK);
	grid[0][6] = new Knight(BLACK);
	grid[0][7] = new Rook(BLACK);
	for (int c = 0; c < 8; c++)
		grid[1][c] = new Pawn(BLACK);
	grid[7][0] = new Rook(WHITE);
	grid[7][1] = new Knight(WHITE);
	grid[7][2] = new Bishop(WHITE);
	grid[7][3] = new Queen(WHITE);
	grid[7][4] = new King(WHITE);
	grid[7][5] = new Bishop(WHITE);
	grid[7][6] = new Knight(WHITE);
	grid[7][7] = new Rook(WHITE);
	for (int c = 0; c < 8; c++)
		grid[6][c] = new Pawn(WHITE);
}
void Board::display()
{
	cout << "\n    a   b   c   d   e   f   g   h\n";
	cout << "  +---+---+---+---+---+---+---+---+\n";
	for (int r = 0; r < 8; r++)
	{
		cout << (8 - r) << " |";
		for (int c = 0; c < 8; c++)
		{
			if (grid[r][c] == nullptr)
				cout << " . |";
			else
				cout << " " << grid[r][c]->getSymbol() << " |";
		}
		cout << " " << (8 - r) << "\n";
		cout << "  +---+---+---+---+---+---+---+---+\n";
	}
}
Piece* Board::getPiece(int r, int c)
{
	return grid[r][c];
}
bool Board::movePiece(int fromRow, int fromCol, int toRow, int toCol)
{
	Piece* piece = grid[fromRow][fromCol];
	if (piece == nullptr)
		return false;
	if (piece->isValidMove(fromRow, fromCol, toRow, toCol, grid) == false)
		return false;
	if (grid[toRow][toCol] != nullptr)
		delete grid[toRow][toCol];
	grid[toRow][toCol] = piece;
	grid[fromRow][fromCol] = nullptr;
	return true;
}
bool Board::kingAlive(int color)
{
	char k;
	if (color == WHITE)
		k = 'K';
	else
		k = 'k';
	for (int r = 0; r < 8; r++)
		for (int c = 0; c < 8; c++)
			if (grid[r][c] != nullptr)
				if (grid[r][c]->getSymbol() == k)
					return true;
	return false;
}