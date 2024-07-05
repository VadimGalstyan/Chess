#include "pawn.h"

Pawn::Pawn(const int& x,const char& y,const std::string& color)
            :
            Figure(x,y,color)
{
    m_name ="PAWN";
}

void Pawn::attack(Board* board)
{
    int i = getX();
    int j = getY();

    if (i - 1 >= 0)
    {
        if (j - 1 >= 0)
        {
            if (board->board[i - 1][j - 1] == nullptr)
            {
                board->checkmateTable[i - 1][j - 1] = false;
            }
            else
            {
                if (board->board[i - 1][j - 1]->getName() == "KING" && board->board[i - 1][j - 1]->getColor() != m_color)
                {
                    board->checkmateTable[i - 1][j - 1] = false;
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

        if (j + 1 < 8)
        {
            if ( board->board[i - 1][j + 1] == nullptr)
            {
                board->checkmateTable[i - 1][j + 1] = false;
            }
            else
            {
                if (board->board[i - 1][j + 1]->getName() == "KING" && board->board[i - 1][j + 1]->getColor() != m_color)
                {
                    board->checkmateTable[i - 1][j + 1] = false;
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
}