#include "board.h"
#include "figure.h"
#include "king.h"
#include "queen.h"
#include "knight.h"
#include "bishop.h"
#include "pawn.h"
#include "rook.h"

int main()
{
    Board board;

    King king(6,'D',"Black");
    board.addFigure(&king);

    King king2(5,'A',"White");
    board.addFigure(&king2);

    Queen q(4,'D',"White");
    board.addFigure(&q);

    Queen b(7,'C',"White");
    board.addFigure(&b);

    Rook r(1,'E',"White");
    board.addFigure(&r);

    
    board.print();
    std::cout<<std::endl;

    if (board.IsCheckmateFor("Black"))
    {
        std::cout<<"Is checkmate"<<std::endl;
    }
    else
    {
        std::cout<<"Is not checkmate"<<std::endl;
    }
        
    // for (size_t i = 0; i < 8; i++)
    // {
    //     for (size_t j = 0; j < 8; j++)
    //     {
    //         if (board.checkmateTable[i][j])
    //         {
    //             std::cout<<"1"<<" ";
    //         }
    //         else
    //         {
    //             std::cout<<"0"<<" ";
    //         }
    //     }
    //     std::cout<<std::endl;
    // }


    return 0;
}