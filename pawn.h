#ifndef __PAWN__
#define __PAWN__

#include "figure.h"

class Pawn : public Figure
{
public:
    Pawn(const int& x,const char& y,const std::string& color);
    void attack(Board* board) override;
};

#endif //__PAWN__