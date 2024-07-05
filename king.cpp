#include "king.h"

King::King(const int& x,const char& y,const std::string& color)
            :
            Figure(x,y,color)
{
    m_name ="KING";
}

void King::attack(Board* board)   
{
    int x = getX();
    int y = getY();

    for (int i = x - 1; i <= x + 1; ++i)
    {
        if (i < 0 || i > 7)
        {
            continue;
        }

        for (int j = y - 1; j <= y + 1; ++j)
        {
            if (j < 0 || j > 7)
            {
                continue;
            }
            
            if (board->board[i][j] == nullptr)
            {
                board->checkmateTable[i][j] = false;
            }
            else
            {
                if (board->board[i][j]->getColor() == m_color)
                {
                    board->checkmateTable[i][j] = false;
                }
                
            }
        }
        
    }
}
