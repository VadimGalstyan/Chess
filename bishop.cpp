#include "bishop.h"

Bishop::Bishop(const int& x,const char& y,const std::string& color)
            :
            Figure(x,y,color)
{
    m_name ="BISHOP";
}

void Bishop::attack(Board* board)
{
    int i = getX() + 1;
    int j = getY() + 1;

    while (i < 8 && j < 8)
    {
        if (board->board[i][j] == nullptr)
        {
            board->checkmateTable[i][j] = false;
            ++i;
            ++j;
        }
        else    
        {
            if (board->board[i][j]->getName() == "KING" && board->board[i][j]->getColor() != m_color)
            {
                board->checkmateTable[i][j] = false;
            }
            break;
        }
    }
    
    i = getX() + 1;
    j = getY() - 1;
    while (i < 8 && j >= 0)
    {

        if (board->board[i][j] == nullptr)
        {
            board->checkmateTable[i][j] = false;
            ++i;
            --j;
        }
        else    
        {
            if (board->board[i][j]->getName() == "KING" && board->board[i][j]->getColor() != m_color)
            {
                board->checkmateTable[i][j] = false;
            }
            break;
        }

    }

    i = getX() - 1;
    j = getY() + 1;
    while (i >= 0 && j < 8)
    {
        if (board->board[i][j] == nullptr)
        {
            board->checkmateTable[i][j] = false;
            --i;
            ++j;

        }
        else    
        {
            if (board->board[i][j]->getName() == "KING" && board->board[i][j]->getColor() != m_color)
            {
                board->checkmateTable[i][j] = false;
            }
            break;
        }
    }

    i = getX() - 1;
    j = getY() - 1;
    while (i >= 0 && j >= 0)
    {
        if (board->board[i][j] == nullptr)
        {

            board->checkmateTable[i][j] = false;
            --i;
            --j;
        }
        else    
        {
            if (board->board[i][j]->getName() == "KING" && board->board[i][j]->getColor() != m_color)
            {
                board->checkmateTable[i][j] = false;
            }
            break;
        }

    }
    
}
