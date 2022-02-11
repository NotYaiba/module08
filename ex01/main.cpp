#include "Swap.hpp"
#include <algorithm>    // std::find
#include <vector>   
int main ()
{
    Swap test(5);
    test.addNumber(1);
    test.addNumber(9);
    test.addNumber(4);
    std::cout << test.longestSpan() << std::endl;

}