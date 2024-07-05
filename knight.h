#ifndef __KNIGHT__
#define __KNIGHT__
#include "figure.h"

class Knight : public Figure
{
public:
    Knight(const int& x,const char& y,const std::string& color);
    void attack(Board* board) override;
};

#endif //__KNIGHT__