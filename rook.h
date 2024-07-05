#ifndef __ROOK__
#define __ROOK__

#include "figure.h"

class Rook : public Figure
{
public:
    Rook(const int& x,const char& y,const std::string& color);
    void attack(Board* board) override;
};

#endif //__ROOK__