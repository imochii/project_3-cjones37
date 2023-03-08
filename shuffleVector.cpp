/**
 * Demonstrate how to shuffle a vector.
 * CS 124
 * University of Vermont
 * Clayton Cafiero
 * 2020-Dec-23
 */

#include <vector>
#include <random>
#include <iostream>

int main() {

    std::random_device rd;  // rd is short for random device

    std::vector<int> v;
    for (int i = 1; i < 11; i++) {
        v.push_back(i);
    }
    // Requires std::random_device rd; from above ^^^
    std::shuffle(v.begin(), v.end(), rd);

    // Prove that it's shuffled
    for (int& n : v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

}
