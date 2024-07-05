#include "figure.h"

Figure::Figure(const int& x,const char& y,const std::string& color)
{
    if (x > 0 && x < 9 && y >= 'A' && y <= 'H' && (color == "White" || color == "Black"))
    {
        m_x = x;
        m_y = y;
        m_color = color;
    }
    else
    {
        std::cout<<"The arguments are invalid!!!"<<std::endl;
    }
}

Figure::~Figure()
{
}


std::string Figure::getColor() const
{
    return m_color;
}


int Figure::getX() const
{
    return 7 - (m_x - 1);
}

int Figure::getY() const
{
    int y = Chars(m_y - 'A');
    return y;
}

std::string Figure::getName() const
{
    return m_name;
}


void Figure::attack(Board* board)
{
}
