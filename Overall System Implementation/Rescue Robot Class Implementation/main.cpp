#include <iostream>
#include "Rescue_Robot.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Rescue_Robot lippstadt(0.0,5.3);
    lippstadt.turn_System_On();
    lippstadt.drive();

    return 0;
}
