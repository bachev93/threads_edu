#include <iostream>
#include <pthread.h>

void* perform_work(void* arg) {
    int passed_arg = *(reinterpret_cast<int*>(arg));
    std::cout << "Hello from thread with argument " << passed_arg << std::endl;
    pthread_exit(0);
}

int main() {
    std::cout << "This is pthreads example" << std::endl;

    const int num_threads = 5;
    pthread_t threads[num_threads];
    int thread_args[num_threads] = {11, 22, 33, 44, 55};

    // create all threads one by one
    int result;
    for (int i = 0; i < num_threads; ++i) {
        std::cout << "In main(): create thread " << i << std::endl;
        result =
            pthread_create(&threads[i], nullptr, perform_work, &thread_args[i]);
        std::cout << "pthread_create() result is: " << result << std::endl;
    }

    // wait for each thread to complete
    for (int i = 0; i < num_threads; ++i) {
        // block until thread i completes
        result = pthread_join(threads[i], nullptr);
        std::cout << "pthread_join() result is: " << result << std::endl;
        std::cout << "In main(): thread " << i << " has completed" << std::endl;
    }

    std::cout << "In main(): All threads completed successfully" << std::endl;

    return 0;
}