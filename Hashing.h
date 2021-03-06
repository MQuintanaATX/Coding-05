/* ************************************************************************
Name: Michael Quintana
Assignment: Coding 05 - Hash Tables
Purpose: Header - hashing
Notes: Servers as the interface for the main Hashing table
************************************************************************ */

#ifndef CODING_05_HASHING_H
#define CODING_05_HASHING_H

#include <string>
#include <iostream>
using namespace std;
/*
 * Structure Definition
 */
struct Node {
    int id;
    string data;
    Node *forward;
};

class Hashing {
private:
    Node* hashtable[19];
    int counter;
public:
    Hashing();
    bool isEmpty();
    bool add(int, string);
    bool contains (int);
    string getData(int);
    int getCountEntries();
    bool remove (int);

    //debug methods
    void printAddress();
    void printValues();
    void clear();
};


#endif //CODING_05_HASHING_H
