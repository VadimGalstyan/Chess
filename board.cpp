#include "board.h"

void figureName(const Figure& obj) 
{
    if (obj.getColor() == "Black")                             //The figures with " ' " this symbol are black figures!!!
    {
        if (obj.getName() == "KING") {std::cout<<"K'  ";}
        if (obj.getName() == "QUEEN") {std::cout<<"Q'  ";}
        if (obj.getName() == "BISHOP") {std::cout<<"B'  ";}
        if (obj.getName() == "KNIGHT") {std::cout<<"k'  ";}
        if (obj.getName() == "PAWN") {std::cout<<"P'  ";}
        if (obj.getName() == "ROOK") {std::cout<<"R'  ";}

    }
    else
    {
        if (obj.getName() == "KING") {std::cout<<"K  ";}
        if (obj.getName() == "QUEEN") {std::cout<<"Q  ";}
        if (obj.getName() == "BISHOP") {std::cout<<"B  ";}
        if (obj.getName() == "KNIGHT") {std::cout<<"k  ";}
        if (obj.getName() == "PAWN") {std::cout<<"P  ";}
        if (obj.getName() == "ROOK") {std::cout<<"R  ";}
    }
    
}

Board::Board()
{
    for (size_t i = 0; i < 8; ++i)
    {
        for (size_t j = 0; j < 8; ++j)
        {
            board[i][j] = nullptr;
            checkmateTable[i][j] = true;
        }
    }
}

void Board::print() const
{
    std::cout<<"The figures with"<< " ' "<<" this symbol are black!"<<std::endl;
    std::cout<<"The 'K' is king,the 'k' is knight!"<<std::endl;
    std::cout<<std::endl;

    for (int i = 0; i < 8; ++i)
    {
        std::cout<<8 - i<<"   ";
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == nullptr)
            {
                // if ((i + j) % 2 == 0)
                // {
                //     std::cout<<"1  ";
                // }
                // else
                // {
                //     std::cout<<"0  ";
                // }
                std::cout<<".  ";
            }
            else
            {
               figureName(*board[i][j]);
            }
            
        }
        std::cout<<std::endl;

    }

    std::cout<<std::endl;
    std::cout<<"    A  B  C  D  E  F  G  H "<<std::endl;
    
}

bool Board::empty() const
{
    for (size_t i = 0; i < 8; ++i)
    {
        for (size_t j = 0; j < 8; ++j)
        {
            if (board[i][j] != nullptr)
            {
                return false;
            }
            
        }
    }
    
    return true;
}

void Board::addFigure(Figure*  fig)
{
//////////ARGUMENTS CHECK//////////////////////////////////////////
    int x = fig->getX();
    char y = fig->getY();
    if (!(x >= 0 && x < 8  && y >= 0 && y < 8))
    {
        std::cout<<"The position is out of range."<<std::endl;
        return;
    }

///////////POSITION CHECK//////////////////////////////////////////
    if (board[x][y] != nullptr)
    {
        std::cout<<"The position is occupied."<<std::endl;
        return;
    }

//IF THE FIGURE IS KING///////////////////////////////////////////////////////////////
////////KINGS COUNT CHECK/////////////////////////////////
    if (fig->getName() == "KING")
    {
        bool thereIsKing = false;
        int kingX = 0;
        int kingY = 0;

        for (size_t i = 0; i < 8; ++i)
        {
            for (size_t j = 0; j < 8; ++j)
            {
                if (board[i][j] != nullptr)
                {
                    if (board[i][j]->getName() == "KING")
                    {
                        if (board[i][j]->getColor() == fig->getColor())
                        {
                            std::cout<<"There is King with that color in the board!!!!"<<std::endl;
                            return;
                        }
                        thereIsKing = true;
                        kingX = i;
                        kingY = j;
                    }
                }
                
            }
        }
        


        ///////KING POSITION CHECK/////////////////////////////////
        if (thereIsKing)
        {
            if(fig->getX() == (kingX - 1))
            {
                if (fig->getY() == (kingY - 1) || fig->getY() == (kingY) || fig->getY() == (kingY + 1))
                {
                    std::cout<<"King cannot be near King!!!!!!"<<std::endl;
                    return;

                }
            } 

            if (fig->getX() == (kingX))
            {
                if (fig->getY() == (kingY - 1) || fig->getY() == (kingY) || fig->getY() == (kingY + 1))
                {
                    std::cout<<"King cannot be near King!!!!!!"<<std::endl;
                    return;
                }
                
            }
            
            if (fig->getX() == (kingX + 1))
            {
                if (fig->getY() == (kingY - 1) || fig->getY() == (kingY) || fig->getY() == (kingY + 1))
                {
                    std::cout<<"King cannot be near King!!!!!!"<<std::endl;
                    return;
                }
                
            }
        }
    }
    
    
//IN OTHER CASES////////////////////////////////////////////////////////
        board[x][y] = fig;  
    
}


bool Board::IsCheckmateFor(const std::string& str)
{


    int kingX = 0;
    int kingY = 0;


    if (str == "Black")
    {
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if (board[i][j] != nullptr)
                {
                    if (board[i][j]->getColor() == "White")
                    {
                        board[i][j]->attack(this);
                    }
                    else
                    {
                        if (board[i][j]->getName() == "KING")
                        {
                            kingX = i;
                            kingY = j;
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    else
    {
        if (str == "White")
        {
            for (int i = 0; i < 8; ++i)
            {
                for (int j = 0; j < 8; ++j)
                {
                    if (board[i][j] != nullptr)
                    {
                        if (board[i][j]->getColor() == "Black")
                        {
                            board[i][j]->attack(this);
                        }
                        else
                        {
                            if (board[i][j]->getName() == "KING")
                            {
                                kingX = i;
                                kingY = j;
                            }
                            
                        }
                    }
                    
                }
            
            }
        }
        else
        {
            std::cout<<"WRONG INPUT (IsCheckmate FUNC)"<<std::endl;
            return false;
        }
        
    }

//CHECKMATE CHECK////////////////////////////////////////////
    if (checkmateTable[kingX][kingY] == true)
    {
        return false;
    }
    else
    {
        for (int i = kingX - 1; i <= kingX + 1; ++i)
        {
            if (i < 0 || i > 7)
            {
                continue;
            }
            
            for (int j = kingY - 1; j <= kingY + 1; ++j)
            {
                if (j < 0 || j > 7)
                {
                    continue;
                }
                if (checkmateTable[i][j] == true)
                {
                    return false;
                }
                
            }
            
        }
        
    }
    

    return true;
}
