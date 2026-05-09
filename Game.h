#ifndef GAME_H
#define GAME_H
#include "Board.h"
class Game
{
private:
    Board board;
    int currentTurn;
    int colToIndex(char c);
    int rowToIndex(int r);
public:
    Game();
    void printWelcome();
    void run();
};
#endif