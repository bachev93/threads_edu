#include <chrono>
#include <iostream>
#include <thread>

int main() {
    while (true) {
        std::cout << "It's daemon programm" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "After waiting" << std::endl;
    }

    return 0;
}
