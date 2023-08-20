#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

std::queue<int> queue;
std::mutex queueMutex;
std::condition_variable queueCondVar;

void provider(int val) {
    // push to queue different values (from val to val + 5 with delays = val
    // milliseconds)
    for (int i = 0; i < 6; ++i) {
        std::lock_guard<std::mutex> lg(queueMutex);
        queue.push(val + i);
    } // release lock
    queueCondVar.notify_one();

    std::this_thread::sleep_for(std::chrono::milliseconds(val));
}

void consumer(int num) {
    // if available, pop values from queue (num value indicates the receiver)
    while (true) {
        int val;
        {
            std::unique_lock<std::mutex> ul(queueMutex);
            // this construction protect code from false alarm from codition
            // variable
            queueCondVar.wait(ul, [] { return !queue.empty(); });
            val = queue.front();
            queue.pop();
        } // release lock
        std::cout << "consumer " << num << ": " << val << std::endl;
    }
}

int main() {
    // run 3 producer threads with values 100+, 300+ and 500+
    auto p1 = std::async(std::launch::async, provider, 100);
    auto p2 = std::async(std::launch::async, provider, 300);
    auto p3 = std::async(std::launch::async, provider, 500);

    // run 2 consumer threads that print values
    auto c1 = std::async(std::launch::async, consumer, 1);
    auto c2 = std::async(std::launch::async, consumer, 2);

    return 0;
}
