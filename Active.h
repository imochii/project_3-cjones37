/**
 * Catherine Jones
 * CS124
 * Section A
 */

#ifndef ACTIVE_H
#define ACTIVE_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

/**
 * Class representing entries in DBKpop's current database for active members in the K-pop industry, otherwise know as the 'Korean pop' industry.
 * Current database sits at 1666 entries. See: https://dbkpop.com/db/all-k-pop-idols/ for source.
 *
 * Fields (naming follows abbreviations used in CSV file):
 *
 *     row: a unique integer indicating the row of data from source
 *
 *     romName: a string indicating the individual's "romanized" name, romanization in this context being the process of phonetically converting a Korean name into English letters.
 *              For foreign fans this might be more recognizable than the individual's 'kName'.
 *
 *     kName: a string indicating the individual's name in Korean.
 *
 *     yOB: an integer indicating the individual's birth year.
 *
 *     primGroup: a string indicating the individual's primary group, as some individuals may be known to work/promote with multiple groups aside from their primary.
 *
 *     country: a string indicating which country the individual is from.
 *
 *     gender: a char indicating the individual's gender, 'F' representing 'female' and 'M' representing 'male'.
 */


class Active
{
private:
    string romName, kName, primGroup, country;
    int row, yOB;
    char gender;

public:

    // constructors

    Active()
    {

    }

    Active(int newRow, string newRomName, string newKName, int newYOB, string newPrimGroup, string newCountry, char newGender)
    {
        row = newRow;
        romName = newRomName;
        kName = newKName;
        yOB = newYOB;
        primGroup = newPrimGroup;
        country = newCountry;
        gender = newGender;
    }

    // GETTERS //
    int getRow() const
    {
        return row;
    }

    string getRomName() const
    {
        return romName;
    }

    string getKName() const
    {
        return kName;
    }

    int getYOB() const
    {
        return yOB;
    }

    string getPrimGroup() const
    {
        return primGroup;
    }

    string getCountry() const
    {
        return country;
    }

    char getGender() const
    {
        return gender;
    }
    //

    // SETTERS //
    void setRow(int newRow)
    {
        row = newRow;
    }

    void setRomName(string newRomName)
    {
        romName = newRomName;
    }

    void setKName(string newKName)
    {
        kName = newKName;
    }

    void setYOB(int newYOB)
    {
        yOB = newYOB;
    }

    void setPrimGroup(string newPrimGroup)
    {
        primGroup = newPrimGroup;
    }

    void setCountry(string newCountry)
    {
        country = newCountry;
    }

    void setGender(char newGender)
    {
        gender = newGender;
    }
    //

    // Overrides
    // You will need to overload the <, >, <=, >=, and == operators of your class from Project 1.
    /**
    * Overload > operator for object comparison
    */
    friend bool operator < (const Active& lhs, const Active& rhs) {
        return lhs.getRow() > rhs.getRow();
    }

    friend bool operator > (const Active& lhs, const Active& rhs) {
        return lhs.getRow() > rhs.getRow();
    }

    /**
     * Overload <= operator for object comparison
     */
    friend bool operator <= (const Active& lhs, const Active& rhs) {
        return lhs.getRow() <= rhs.getRow();
    }

    /**
     * Overload >= operator for object comparison
     */
    friend bool operator >= (const Active& lhs, const Active& rhs) {
        return lhs.getRow() >= rhs.getRow();
    }

    /**
     * Overload == operator for object comparison
     */
    friend bool operator == (const Active& lhs, const Active& rhs) {
        return lhs.getRow() == rhs.getRow();
    }

    /**
     * Overload != operator for object comparison
     */
    friend bool operator != (const Active& lhs, const Active& rhs) {
        return lhs.getRow() != rhs.getRow();
    }

/**
* Overload stream insertion operator for pretty printing
*/
    friend std::ostream& operator << (std::ostream& outs, const Active& person)
    {
        outs << std::fixed
             << std::right
             << std::setprecision(4)
             << std::setw(12) << person.getRow()
             << std::setw(20) << person.getRomName()
             << std::setw(20) << person.getKName()
             << std::setw(12) << person.getYOB()
             << std::setw(20) << person.getPrimGroup()
             << std::setw(20) << person.getCountry()
             << std::setw(12) << person.getGender()
             << std::endl;
        return outs;
    }
};
// END OF ACTIVE CLASS

/**
* Read data into a vector from the downloaded CSV file.
* Returns true if everything goes well; false otherwise.
*/

bool fileCheck(string fn, vector<Active>& objs) {
    ifstream fin;
    fin.open(fn);

    // if it goes wrong
    if (!fin) {
        return false;
    }

    // successful file opening //

    // toss header line: read it and throw it away
    std::string header = "";
    getline(fin, header);

    // while file is good and haven't hit EOF
    int counter = 1;
    while (fin && fin.peek() != EOF) {
        // FAILSAFE: initialize to sentinel values to catch data that was incorrectly set
        string romName = "INVALID";
        string kName = "INVALID";
        string primGroup = "INVALID";
        string country = "INVALID";

        int row = -1;
        int yOB = -1;

        char gender = 'X';  // 'X' for 'Wrong'
        char comma = ',';  // This will come in handy apparently

        // Using the >> (extraction) operator
        fin >> row;  // Expects an int; reads an int
        if (row != counter) {
            std::cout << row << " != " << counter << std::endl;
            return false;
        }

        fin >> comma;

        // These read a string, comma is delimiter
        getline(fin, romName, comma);
        getline(fin, kName, comma);

        fin >> yOB;

        fin >> comma;

        // back to strings
        getline(fin, primGroup, comma);

        if (!fin) // primGroup might be empty, likely an indication of a solo artist
        {
            primGroup = romName + '/' + kName;      // replace 'group' name with name of artist
            fin.clear(); // ???????????????????
        }

        getline(fin, country, comma);

        if (fin.peek() != '\r' && fin.peek() != '\n')
        {
            fin >> gender;
        }

        Active artist(row, romName, kName, yOB, primGroup, country, gender);
        objs.push_back(artist);

        counter += 1;
    }

    fin.close();
    return true;
}

/**
 * Given a vector of active K-pop artists, find the average year of birth.
 */
void averageYOB(vector<Active>& artist)
{
    int average = 0;
    int counter = 0;
    int sum = 0;

    for(Active& person : artist)
    {
        int year = person.getYOB();

        sum = sum + year;

        counter+=1;
    }

    average = sum/counter;

    cout << endl;

    std::cout << "Average year of birth of active artists: " << average << std::endl;
}

/**
 * testing testing please don't fail
 */
void test()
{
    Active testObject = Active();

    // Test setters and getters
    testObject.setRow(1104);
    assert (testObject.getRow() == 1104);
    testObject.setRomName("Kim Namjoon");
    assert (testObject.getRomName() == "Kim Namjoon");
    testObject.setKName("김남준");
    assert (testObject.getKName() == "김남준");
    testObject.setYOB(1994);
    assert (testObject.getYOB() == 1994);
    testObject.setPrimGroup("BTS");
    assert (testObject.getPrimGroup() == "BTS");
    testObject.setCountry("South Korea");
    assert (testObject.getCountry() == "South Korea");
    testObject.setGender('M');
    assert (testObject.getGender() == 'M');
}

#endif // ACTIVE_H
