/**
 * Demonstrate how time events in C++.
 * CS 124
 * University of Vermont
 * Clayton Cafiero
 * 2020-Dec-23
 */

#include <iostream>
#include <chrono>

int main() {

    int x = 1;
    int y = 0;
    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        ++x;
        ++y;
        int temp = x;
        x = y;
        y = temp;
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>
            (endTime - startTime).count();
    std::cout << "The time it takes to increment "
              << "and swap two int variables one million times is "
              << duration << " microseconds." << std::endl;

}
