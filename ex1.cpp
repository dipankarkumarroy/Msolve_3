#include <iostream>
#include <iomanip>
#include "Msolve3.hpp"
int main()
{
    
    std::cout << std::fixed << std::setprecision(10);
    std::cout << Msolve("(x+w+(w+(x-w+(x*fmin(x,w)))))",1,9) << '\n';

}
