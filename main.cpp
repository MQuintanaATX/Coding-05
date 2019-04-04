/* ************************************************************************
Name: Michael Quintana
Assignment: Coding 05 - Hash Tables
Purpose: Implementation - main
Notes: Implementation file serving as the main driver for the program
 Change the value in line 400 to determine number of loops
************************************************************************ */
#include "main.h"

int main (int argc,char** argv) {
    srand (time(NULL));
    cout << "******Beginning Coding 05 - Hash Tables******" << endl;
    /*Handles the initial parameters passed in*/
    if (argc != 2) { //Checks for additional arguments that are not intended
        cout <<  "You have specified too many or too few arguments. Please try again.";
        return 3;
    }
    //Obtains the char array from argv, and opens the file
    string userInput(argv[1]);
    ifstream filename;
    //Checks for the file, and exits if no file exists
    filename.open(userInput.c_str());
    if (!filename) {
        cout << "There is no file named : " << userInput << ". Please check for the file, and try again." << endl;
    }
    int lineCount = 0; //holds the tally of lines in the file
    try {
        lineCount = countLines(filename);
        if (lineCount == 0) {
            cout <<  "THere is no data in your file. Please try again." << endl;
            return -1;
        }
        cout << lineCount;
    }
    catch (...){
        cout << "An error occured. Unable to determmine amount of lines..";
        return 0;
    }

    Hashing table; //The hash table
    cout << boolalpha;
    cout << "table.isEmpty - ";
    cout << table.isEmpty();
    cout << endl << "> Number of table entries | ";

    filename.clear();
    filename.seekg(0);

    cout << endl << endl << "> Now loading data into hash table" << endl;
    int counter;
    while (!filename.eof()) {
        string fileString, container; // Container is used to parse data
        int id;
        string data;
        getline(filename, fileString);
        if (fileString == "\0"){ // checks for a blank line, and skips parsing if that's the csae
            continue;
        }
        for (int i = 0; i < fileString.size(); i++) {
            if (fileString[i] != ',') {
                container += fileString[i];
                continue;
            } else if (fileString[i] == ','){
                id = stoi(container);
                container = "";
            }
        }
        cout << id << ", " << container << " | table.add() = ";
        cout << table.add(id, container);
        cout << " | table.isEmpty() = ";
        cout << table.isEmpty() << endl;
    }
    cout << "# of Entries: " << table.getCountEntries();

    cout << endl << "> Finding values" << endl;
    //Searching for values in the 1st, 2nd, and 3rd parts of the chain
    cout << "Contains 131: ";
    cout << table.contains(131) << endl;
    cout << "Contains 238: ";
    cout << table.contains(238) << endl;
    cout << "Contains 195: ";
    cout << table.contains(195) << endl;
    cout << "Contains 1: ";
    cout << table.contains(1) << endl;
    cout << "Contains 922: ";
    cout << table.contains(922) << endl;

    cout << endl << "> Retrieving data" << endl;
    //Searching for values in the 1st, 2nd, and 3rd parts of the chain
    cout << "Contains 131: ";
    cout << table.getData(131) << endl;
    cout << "Contains 238: ";
    cout << table.getData(238) << endl;
    cout << "Contains 195: ";
    cout << table.getData(195) << endl;
    cout << "Contains 1: ";
    cout << table.getData(1) << endl;
    cout << "Contains 922: ";
    cout << table.getData(922) << endl;

    cout << endl << "> Deleting values" << endl;
    cout << "Deleting 115: ";
    cout << table.remove(115) << endl;
    cout << "Deleting 238: ";
    cout << table.remove(238) << endl;
    cout << "Deleting 195: ";
    cout << table.remove(195) << endl;
    cout << "# of Entries: " << table.getCountEntries();

    cout << endl << ">Automated, high volume testing" << endl;
    //Tests all of the previous entered values in data csv for removal.
    int testarray[] = {100, 108, 117, 129, 157, 205, 155, 131, 156,
                       195, 115, 208, 132, 777,  991, 485, 828, 238, 555, 941};
    int testint = 0;
    for (int i = 0; i < 40; i++) {
        if (i < 20){ //Ensures deletion testing of all original values
            testint = testarray[i];
        } else { // assignes a random int once past that
            testint = randomInt();
        }
        if (i <= 20) {
            cout << "Contains " << testint << ": ";
            cout << table.contains(testint) << endl;
            cout << "Data is " << testint << ": ";
            cout << table.getData(testint) << endl;
            cout << "Deleting " << testint << ": ";
            cout << table.remove(testint) << endl;
            cout << "# of Entries: " << table.getCountEntries() << endl << endl;
            //Ensures that every  other loop  tests removal. Helps build a list for clear
            //Also checks to ensure the list isn't added in a lopsided method.
            //Should only ever have (n/2) - 10 cases
        }  else if (i % 2 == 0){
            cout << "Adding " << testint << ": ";
            cout << table.add(testint, "Test " + to_string(testint)) << endl;
            cout << "Contains " << testint << ": ";
            cout << table.contains(testint) << endl;
            cout << "Data is " << testint << ": ";
            cout << table.getData(testint) << endl;
            cout << "Deleting " << testint << ": ";
            cout << table.remove(testint) << endl;
            cout << "# of Entries: " << table.getCountEntries() << endl << endl;
        } else {
            cout << "Adding " << testint << ": ";
            cout << table.add(testint, "Test " + to_string(testint)) << endl;
            cout << "Contains " << testint << ": ";
            cout << table.contains(testint) << endl;
            cout << "Data is " << testint << ": ";
            cout << table.getData(testint) << endl;
            cout << "# of Entries: " << table.getCountEntries() << endl << endl;
        }
    }
    cout << "Clearing table..." << endl << endl;
    table.clear();
    cout << "Verifying table clear: " << endl;
    for (int i = 0; i < 3; i++){
        cout << "Contains " << testarray[i] << ": ";
        cout << table.contains(testarray[i]) << endl;
        cout << "# of Entries: " << table.getCountEntries() << endl << endl;
    }


    cout << endl << "******Ending Coding 05 - Hash Tables******" << endl;
    return 0;
}