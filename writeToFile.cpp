/**
 * Write "The Frog" to file. A haiku by Basho, with
 * English translation by Allen Ginsberg.
 * CS 124
 * University of Vermont
 * Clayton Cafiero
 * 2020-Dec-23
 *
 * Translation of Basho's Frog by Allan Ginsburg.
 */

#include <fstream>
#include <iostream>

int main() {

    std::ofstream outFile("../data/frog.txt");
    if (outFile.is_open()) {
        outFile << "The old pond:" << std::endl;
        outFile << "A frog jumped in." << std::endl;
        outFile << "Kerplunk!" << std::endl;
        outFile.close();
    } else {
        std::cout << "Unable to open output file!" << std::endl;
        return 1;
    }

    return 0;
}