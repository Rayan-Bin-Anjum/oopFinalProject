#include "Game.h"
#include <stdexcept>
Game::Game()
{
    currentTurn = WHITE;
}
int Game::colToIndex(char c)
{
    if (c < 'a' || c > 'h')
    {
        throw std::invalid_argument("Column must be between a and h");
    }
    return c - 'a';
}
int Game::rowToIndex(int r)
{
    if (r < 1 || r > 8)
    {
        throw std::out_of_range("Row must be between 1 and 8");
    }
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
    while (true)
    {
        board.display();
        if (currentTurn == WHITE)
        {
            cout << "  >>> WHITE's turn\n";
        }
        else
        {
            cout << "  >>> BLACK's turn\n";
        }
        cout << "  Enter move: ";
        string input;
        getline(cin, input);
        if (input == "quit")
        {
            break;
        }
        if (input.size() < 5)
        {
            cout << "  [!] Error: Input too short!\n";
            continue;
        }
        try
        {
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
                        {
                            enemy = BLACK;
                        }
                        else
                        {
                            enemy = WHITE;
                        }
                        if (board.kingAlive(enemy) == false)
                        {
                            board.display();
                            cout << "  *** CHECKMATE! ***\n";
                            break;
                        }
                        if (currentTurn == WHITE)
                        {
                            currentTurn = BLACK;
                        }
                        else
                        {
                            currentTurn = WHITE;
                        }
                        continue;
                    }
                }
            }
            cout << "  [!] Invalid move!\n";
        }
        catch (const std::invalid_argument& e)
        {
            cout << "  [!] Input Error: " << e.what() << "\n";
        }
        catch (const std::out_of_range& e)
        {
            cout << "  [!] Bounds Error: " << e.what() << "\n";
        }
        catch (...)
        {
            cout << "  [!] An unknown error occurred handling your move.\n";
        }
    }
}