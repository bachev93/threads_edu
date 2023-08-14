#include <future>
#include <iostream>
#include <string>

bool is_odd(int val) {
    std::cout << "checking if value is odd" << std::endl;
    return val % 2;
}

int main() {
    auto fut = std::async(is_odd, 90);

    auto result = fut.get();
    if (result) {
        std::cout << "val is odd" << std::endl;
    } else {
        std::cout << "val is even" << std::endl;
    }

    return 0;
}