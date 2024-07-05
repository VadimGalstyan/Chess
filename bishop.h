#ifndef __BISHOP__
#define __BISHOP__
#include "figure.h"

class Bishop : public Figure
{
public:
    Bishop(const int& x,const char& y,const std::string& color);
    void attack(Board* board) override;
};

#endif //__BISHOP__