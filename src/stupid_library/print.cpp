#include "stupid_library/print.hpp"
#include <fmt/format.h>
#include <spdlog/spdlog.h>

void print(std::string text)
{

    std::cout << text << "\n";
    //
    std::cout << "FMT: "
              << FMT_VERSION << " \n";
}