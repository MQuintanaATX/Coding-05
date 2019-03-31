/* ************************************************************************
Name: Michael Quintana
Assignment: Coding 05 - Hash Tables
Purpose: Implementation - main
Notes: Implementation file for functions used in the main driver
************************************************************************ */

#include "Functions.h"

int countLines(ifstream& filename) {
    int count = 0;
    //Holds the contents of the file while reading
    string contents;
    while (getline(filename, contents)){
        // if that line is empty, skips that line. This allows for parsing of files with bank lines
        if (contents == "\0"){
            continue;
        }
        count++;
    }
    return count;
}
