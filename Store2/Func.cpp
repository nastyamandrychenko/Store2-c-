#include "Authorization.h"
#include "Product.h"
#include "Func.h"
#include "Television.h"
#include "Phone.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include  <sstream>

void check(string& str) {

    while (str.find_first_not_of("0123456789") != string::npos) {
        cout << "Not integer!";
        cin.ignore();
        cin >> str;
    };

};

void deleteProductFromFile(const string& filename, int lineToDelete) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    vector<string> lines; // is used to store the lines of the file that are not to be deleted
    string line;
    int lineNumber = 1;
    while (getline(file, line)) {
        if (lineNumber != lineToDelete) {
            lines.push_back(line);
        };
        lineNumber++;
    };
    file.close();

    // Clear the file
    ofstream clearFile(filename, ofstream::out | ofstream::trunc);
    if (!clearFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    };
    clearFile.close();
    // Write the modified content back to the file
    ofstream backToFile(filename, ios_base::app);
    if (!backToFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    for (const string& modifiedLine : lines) {
        backToFile << modifiedLine << endl;
    }
    backToFile.close();
};
