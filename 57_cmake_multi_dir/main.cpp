#include <iostream>
#include "add.h"

int main(int argc, char** argv)
{
    int sum = add(1, 3);
    std::cout << "The sum of 1 and 3 is " << sum << std::endl;
    return 0;
}
