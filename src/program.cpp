#include <iostream>
#include "ATM.h"

int main()
{
    IMD::account ac = IMD::account(20050923, 100'000);
    std::cout << std::boolalpha << ac.check_pincode(20050922) << std::endl;
    std::cout << std::boolalpha << ac.check_pincode(20040822) << std::endl;
    std::cout << std::boolalpha << ac.check_pincode(20050923) << std::endl;

    std::cin.get();

    return 0;
}