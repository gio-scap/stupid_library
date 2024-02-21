#include "stupid_library/print.hpp"
#include "config.hpp"
#include <nlohmann/json.hpp>

int main()
{
    std::cout << project_name << "\n"
              << project_version << "\n";
    print("tutto ok!");
    std::cout << "JSON LIB VERSION " << NLOHMANN_JSON_VERSION_MAJOR << "\n";
    //
}
