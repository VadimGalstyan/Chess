#ifndef __BOARD__
#define __BOARD__
#include "figure.h"
class Figure;


class Board
{
public:
    Board();
    void addFigure(Figure* fig);
    bool empty() const;

    void print() const;

    bool IsCheckmateFor(const std::string& str);

    Figure* board[8][8];
    bool checkmateTable[8][8];

};

#endif //__BOARD__