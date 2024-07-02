#include "stupid_library/stupid_library.hpp"
#include "config.hpp"

// #include <nlohmann/json.hpp>

int main()
{
    std::cout << project_name << "\n"
              << project_version << "\n";
    print("tutto ok!");
    // std::cout << "JSON LIB VERSION " << NLOHMANN_JSON_VERSION_MAJOR << "\n";
    //

    int i;

    // int x[2];
    // x[2] = 3; // out of bounds! Compiler doesn't find this only sanitizer does

    // std::shared_ptr<simulator::UnityBridge> ptr;
    // ptr = simulator::UnityBridge::getPtr();

    // simulator::CarParameters param;
    // simulator::CarPtr car = simulator::Car::getPtr(simulator::Car::PHYSX,param );
    // ptr->addCar(car);

    // cv::Mat image;
    // std::cout << "OpenCV version: " << CV_VERSION << std::endl;
}
