#include "queen.h"

Queen::Queen(const int& x,const char& y,const std::string& color)
            :
            Figure(x,y,color)
{
    m_name ="QUEEN";
}

void Queen::attack(Board* board)
{
//ROOK AND BISHOP ATTACKS MIX////////////////////////////////
//ROOK PART////////////
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

//BISHOP PART////////////////////////////////////

    i = getX() + 1;
    j = getY() + 1;

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