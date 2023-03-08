/**
 * Catherine Jones
 * CS124
 * Section A
 */

#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include "Active.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

int main()
{
    int depth = 0;
    assert (depth == 0);

    BinarySearchTree<int> ofIntBST1;    // create int BST
    AVLTree<int> ofIntAVL1;  // create int AVL
    SplayTree<int> ofIntSplay1;  // create int splay

        // loop 100x in order
    for (int i = 1; i <= 100; i++)
    {
        ofIntBST1.add(i);    // add numbers 1-100 into BST
        ofIntAVL1.add(i);    // add numbers 1-100 into AVL
        ofIntSplay1.add(i);  // add numbers 1-100 into Splay
    }

    assert (ofIntBST1.isEmpty() != true);       // testing
    assert (ofIntAVL1.isEmpty() != true);       // testing
    assert (ofIntSplay1.isEmpty() != true);     // testing

        // creating and opening a file
    ofstream outFile1;
    outFile1.open("../outFile1.txt");

        // header
    outFile1 << setw(10) << "Value: " << setw(10)<< "BST: " << setw(10) << "AVL: " << setw(10) << "Splay: " << endl;
        // loop 100x to find in order
    for (int i = 1; i <= 100; i++)
    {
        outFile1 << setw(10) << i;      // so we can see what value we're referencing

        ofIntBST1.find(i, depth);
        outFile1 << setw(10) << depth;

        ofIntAVL1.find(i, depth);
        outFile1 << setw(10) << depth;

        ofIntSplay1.find(i, depth);
        outFile1 << setw(10) << depth << endl;
    }

    assert (ofIntBST1.find(10, depth) == true);     // testing
    assert (ofIntAVL1.find(10, depth) == true);     // testing
    assert (ofIntSplay1.find(10, depth) == true);       // testing

        // check for understanding
    cout << "Check for understanding:" << endl;
    ofIntBST1.find(1, depth);
    cout << "The values and depth returned from a BST search for value 0: " << depth << endl;
    assert (ofIntBST1.find(1, depth) == true);     // testing

    ofIntBST1.find(101, depth);
    cout << "The values and depth returned from a BST search for value 101: " << depth << endl;
    assert (ofIntAVL1.find(0, depth) != true);     // testing

    ofIntBST1.find(102, depth);
    cout << "The depth returned from a BST search for value 102: " << depth << endl;
    assert (ofIntSplay1.find(0, depth) != true);     // testing

        // close the file
    outFile1.close();

    // --------------------------------------------------------

    BinarySearchTree<int> ofIntBST2;    // create int BST
    AVLTree<int> ofIntAVL2;  // create int AVL
    SplayTree<int> ofIntSplay2;  // create int splay

    assert (ofIntBST2.isEmpty() == true);       // testing
    assert (ofIntAVL2.isEmpty() == true);       // testing
    assert (ofIntSplay2.isEmpty() == true);     // testing

    vector<int> vec;    // create a vector
    for (int i = 1; i <= 100; i++)   // fill vector
    {
        vec.push_back(i);
    }

    assert (vec.size() == 100);     // testing

        // shuffle shuffle shuffle
    shuffle(vec.begin(), vec.end(), random_device());

    // COMPARE PRE=SHUFFLE AND POST-SHUFFLE!!!!!!!!!!!!!!!!

        // loop 100x
    for (int i = 0; i <= 100; i++)
    {
        int rand = vec[i];

        ofIntBST2.add(rand);    // add randomized number 1-100 to BST
        ofIntAVL2.add(rand);    // add randomized number 1-100 to AVL
        ofIntSplay2.add(rand);  // add randomized number 1-100 to splay
    }

        // creating and opening a file
    ofstream outFile2;
    outFile2.open("../outFile2.txt");

        // header
    outFile2 << setw(10) << "Value: " << setw(10) << "BST: " << setw(10) << "AVL: " << setw(10) << "Splay: " << endl;
        // loop 100x to find in order
    for (int i = 1; i <= 100; i++)
    {
        outFile2 << setw(10) << i;

        ofIntBST2.find(i, depth);
        outFile2 << setw(10) << depth;  // find in BST and write to file

        ofIntAVL2.find(i, depth);
        outFile2 << setw(10) << depth;  // find in AVL and write to file

        ofIntSplay2.find(i, depth);
        outFile2 << setw(10) << depth << endl;    // find in Splay1 and write to file
    }

    assert (ofIntBST2.find(10, depth) == true);     // testing
    assert (ofIntAVL2.find(10, depth) == true);     // testing
    assert (ofIntSplay2.find(10, depth) == true);       // testing

        // close the file
    outFile2.close();

    // --------------------------------------------------------

    vector<Active> artist;

    string file = "../Active-in-Kpop.csv";

    if (fileCheck(file, artist))
    {
        BinarySearchTree<Active> activeBST;    // create custom BST
        AVLTree<Active> activeAVL;  // create custom AVL
        SplayTree<Active> activeSplay1;  // create first custom splay
        SplayTree<Active> activeSplay2;  // create second custom splay

        assert (artist.size() > 1000);      // testing

            // insert in the order of the vector
        for (int i = 0; i < artist.size(); i++)
        {
            activeBST.add(artist.at(i));    // add to BST
            activeAVL.add(artist.at(i));    // add to AVL
            activeSplay1.add(artist.at(i));    // add to Splay1
        }

            // creating and opening a file
        ofstream outFileCustom1;
        outFileCustom1.open("../outFileCustom1.txt");

            // header
        outFileCustom1 << setw(10) << "Value: " << setw(10) << "BST: " << setw(10) << "AVL: " << setw(10) << "Splay: " << endl;
            // find each object and record the depth
        for (int i = 0; i < artist.size(); i++)
        {
            outFileCustom1 << setw(10) << i;

            activeBST.find(artist.at(i), depth);
            outFileCustom1 << setw(10) << depth;    // find in BST and write to file

            activeAVL.find(artist.at(i), depth);
            outFileCustom1 << setw(10) << depth;    // find in AVL and write to file

            activeSplay1.find(artist.at(i), depth);
            outFileCustom1 << setw(10) << depth << endl;    // find in Splay1 and write to file
        }

        assert (activeBST.find(artist.at(10), depth) == true);     // testing
        assert (activeAVL.find(artist.at(10), depth) == true);     // testing
        assert (activeSplay1.find(artist.at(10), depth) == true);     // testing

            // close the file
        outFileCustom1.close();

            // creating and opening a file
        ofstream outFileCustom2;
        outFileCustom2.open("../outFileCustom2.txt");

            // second splay
        for (int i = 0; i < artist.size(); i++)
        {
            activeSplay2.add(artist.at(i));    // add to Splay2
        }

            // header
        outFileCustom2 << setw(10) << "Value: " << setw(10) << "Splay x1: " << setw(10) << "Splay x2: " << setw(10) << "Splay x3: " << setw(10) << "Splay x4: " << setw(10) << "Splay x5: " << endl;
            // find each object five times in a row before searching for the next object, and record the depths to a file
        for (int i = 0; i < artist.size(); i++)
        {
            outFileCustom2 << setw(10) << i;

            for (int x = 0; x < 4; x++)     // x4
            {
                activeSplay2.find(artist.at(i), depth);
                outFileCustom2 << setw(10) << depth;    // find in Splay2 and write to file
            }

            activeSplay2.find(artist.at(i), depth);
            outFileCustom2 << setw(10) << depth << endl;
        }

        assert (activeSplay2.find(artist.at(10), depth) == true);     // testing

            // close the file
        outFileCustom2.close();
    }
    else
    {
        cout << "Something went wrong :/" << endl;
    }

    // --------------------------------------------------------

    return 0;   // FINALLYYYYYYYYYY
}