/**
 * Tests to compare the depths of find operations using
 * trace file for simulation
 */

#include <fstream>
#include <iostream>
#include <string>
#include "SplayTree.h"


/**
 * Instantiate a splay tree with splayOnAdd set to boolean
 * parameter supplied. Then read through trace file, count
 * depths, and return sum of depths.
 */
float calcAverageDepth(bool splayOnAdd) {

    SplayTree<int> splayTree(splayOnAdd);

    std::ifstream fin;
    fin.open("../splay_trace.csv");

    if (!fin) {
        // Bad file / could not open
        std::cout << "Could not open trace file." << std::endl;
    }

    int sumOfDepths = 0;  // The cumulative sum of depths over all operations
    int operations = 0;  // The number of operations performed, i.e., add or find
    while (fin && fin.peek() != EOF) {
        std::string action;
        std::string valString;
        int value;
        char comma = ',';
        std::getline(fin, action, comma);
        std::getline(fin, valString);
        value = std::stoi(valString);

        // Add code here to add a value if the action is "add" or
        // find a value if the action is "find". Be sure to measure
        // correctly the depth of the tree on find operations and
        // to calculate the sum of depths in the variable `sumOfDepths`



        // End add code here
        operations++;
    }
    float averageDepth = (float)sumOfDepths / (float)operations;
    return averageDepth;
}


int main() {

    std::cout << std::setprecision(4);

    // Experiment #1: splay on add set to false
    float averageDepth = calcAverageDepth(false);
    std::cout << "Splay on add = false" << std::endl;
    std::cout << "Average depth = " << averageDepth << std::endl;

    // Experiment #2: splay on add set to true
    averageDepth = calcAverageDepth(true);
    std::cout << "Splay on add = true" << std::endl;
    std::cout << "Average depth = " << averageDepth << std::endl;

    return 0;
}
