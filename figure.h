#ifndef __FIGURE__
#define __FIGURE__

#include <iostream>
#include "board.h"
class Board;

enum Chars
{
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H
};


class Figure
{
public:
    int getY() const;
    int getX() const;
    std::string getColor() const;
    std::string getName() const;
    virtual void attack(Board* board);


protected:
    Figure(const int& x,const char& y,const std::string& color);
    virtual ~Figure();


    int m_x = 0;
    char m_y = 0;

    std::string m_color;
    std::string m_name;
};

#endif //__FIGURE__