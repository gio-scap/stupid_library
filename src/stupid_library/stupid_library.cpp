#include "stupid_library/stupid_library.hpp"
#include <fmt/format.h>
#include <spdlog/spdlog.h>

void print(std::string text)
{

    std::cout << text << "\n";
    //
    std::cout << "FMT: "
              << FMT_VERSION << " \n";
}

// function for catch2 example

unsigned int factorial(unsigned int number)
{
    return number <= 1 ? 1 : factorial(number - 1) * number;
}
