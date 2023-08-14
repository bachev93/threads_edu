#include <iostream>
#include <string_view>
#include <thread>

void task(std::string_view msg) {
    std::cout << "task says: " << msg << std::endl;
}

int main() {
    std::string_view msg = "I am task 1";
    std::thread t(task, msg);
    t.join();

    return 0;
}
