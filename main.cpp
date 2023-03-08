/**
 * What a fabulous docblock!
 * Yay!
 */

#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include <fstream>

int main() {
    // Example of writing out to a file
    std::ofstream outFile;
    outFile.open("../data/example_output.csv");
    for (int i = 999; i >= 0; --i) {
        outFile << i << std::endl;
    }
    outFile.close();

    BinarySearchTree<int> bst1;
    bst1.add(8);
    bst1.timber();

    return 0;
}