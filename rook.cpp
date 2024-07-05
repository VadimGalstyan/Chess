#include "rook.h"

Rook::Rook(const int& x,const char& y,const std::string& color)
            :
            Figure(x,y,color)
{
    m_name ="ROOK";
}

void Rook::attack(Board* board)
{
    int i = getX() - 1;
    int j = getY();


    while (i >= 0)
    {
        if (board->board[i][j] == nullptr)
        {
            board->checkmateTable[i][j] = false;
            --i;
        }
        else
        {
            if (board->board[i][j]->getName() == "KING" && board->board[i][j]->getColor() != m_color)
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
            break;
        }
    }
    
    i = getX() + 1;
    while (i < 8)
    {
        if (board->board[i][j] == nullptr)
        {
            board->checkmateTable[i][j] = false;
            ++i;
        }
        else
        {
            if (board->board[i][j]->getName() == "KING" && board->board[i][j]->getColor() != m_color)
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
            break;
        }
    }
    
    i = getX();
    --j;

    while (j >= 0)
    {
        if (board->board[i][j] == nullptr)
        {
            board->checkmateTable[i][j] = false;
            --j;
        }
        else
        {
            if (board->board[i][j]->getName() == "KING" && board->board[i][j]->getColor() != m_color)
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
            break;
        }
    }
    
    j = getY() + 1;

    while (j < 8)
    {
        if (board->board[i][j] == nullptr)
        {
            board->checkmateTable[i][j] = false;
            ++j;
        }
        else
        {
            if (board->board[i][j]->getName() == "KING" && board->board[i][j]->getColor() != m_color)
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
            break;
        }
    }
}