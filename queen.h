#ifndef __QUEEN__
#define __QUEEN__

#include "figure.h"

class Queen : public Figure
{
public:
    Queen(const int& x,const char& y,const std::string& color);
    void attack(Board* board) override;
};

#endif //__QUEEN__