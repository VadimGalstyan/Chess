#include "king.h"

King::King(const int& x,const char& y,const std::string& color)
            :
            Figure(x,y,color)
{
    m_name ="KING";
}

void King::attack(Board* board)   //For checking the checkmate without steps king's attack not useful,because kings cannot shah each other!!
{
}
