#include "Game.h"
Game::Game()
{
	currentTurn = WHITE;
}
int Game::colToIndex(char c)
{
	return c - 'a';
}
int Game::rowToIndex(int r)
{
	return 8 - r;
}
void Game::printWelcome()
{
	cout << "========================================\n";
	cout << "  Enter moves like: e2 e4\n";
	cout << "  Type 'quit' to exit\n";
	cout << "========================================\n";
}
void Game::run()
{
	while (1)
	{
		board.display();
		if (currentTurn == WHITE)
			cout << "  >>> WHITE's turn\n";
		else
			cout << "  >>> BLACK's turn\n";
		cout << "  Enter move: ";
		string input;
		getline(cin, input);
		if (input == "quit")
			break;
		if (input.size() < 5)
			continue;
		int fC = colToIndex(input[0]);
		int fR = rowToIndex(input[1] - '0');
		int tC = colToIndex(input[3]);
		int tR = rowToIndex(input[4] - '0');
		Piece* p = board.getPiece(fR, fC);
		if (p != nullptr)
		{
			if (p->getColor() == currentTurn)
			{
				if (board.movePiece(fR, fC, tR, tC))
				{
					int enemy;
					if (currentTurn == WHITE)
						enemy = BLACK;
					else
						enemy = WHITE;
					if (board.kingAlive(enemy) == false)
					{
						board.display();
						cout << "  *** CHECKMATE! ***\n";
						break;
					}
					if (currentTurn == WHITE)
						currentTurn = BLACK;
					else
						currentTurn = WHITE;
					continue;
				}
			}
		}
		cout << "Invalid move! " << endl;
	}
}