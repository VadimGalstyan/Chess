#ifndef __KING__
#define __KING__
#include "figure.h"

class King : public Figure
{
public:
    King(const int& x,const char& y,const std::string& color);
    void attack(Board* board) override;
};

#endif //__KING__