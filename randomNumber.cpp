/**
 * Demonstrate how to pick a random integer.
 * CS 124
 * University of Vermont
 * Clayton Cafiero
 * 2020-Dec-23
 *
 * You may see stuff like this
 *
 *     int n = rand() % 100;   // kinda pseudo-random # between 0 - 99
 *
 * This ^ is fine for our purposes, and you can use this in your project,
 * but is a bad idea in real-world applications (for complicated reasons
 * beyond the scope of this course). Here's a better way (below).
 *
 * If you're curious about std::mt19937 see:
 *
 * http://www.cplusplus.com/reference/random/mt19937/
 * https://en.wikipedia.org/wiki/Mersenne_Twister
 *
 * Note: default_random_engine is not recommended
 */

#include <random>
#include <iostream>

int main() {

    std::random_device rd;  // rd is short for random device
    std::mt19937 mt(rd());  // mt is short for Mersenne twister
    std::uniform_int_distribution<int> distribution(0, 99);
    // ^ We're going to choose a random # between 0 and 99
    int randomInteger = distribution(mt);
    std::cout << randomInteger << std::endl;

}
