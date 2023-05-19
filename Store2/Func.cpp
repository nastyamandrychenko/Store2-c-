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
using namespace std;

void deleteProductFromFile(const string& filename, int lineToDelete) {
    try {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Error opening file: " + filename);
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
        throw runtime_error("Error opening file for writing: " + filename);
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
    }
    catch (const exception& e) {
        cerr << "Exception occurred: " << e.what() << endl;
        //handles any other exceptions that may occur
    }
};

void displayProducts() {
    cout << "Choose the product group to display:" << endl;
    cout << "1. Televisions" << endl;
    cout << "2. Phones" << endl;
    cout << "Enter your choice: ";
    int productGroup;

    if (!(cin >> productGroup)) {
        cout << "Invalid input. Please enter an integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (productGroup == 1) {
        vector<Television*> televisions = readData<Television>("television.txt");
        displayProducts(televisions);
    }
    else if (productGroup == 2) {
        vector<Phone*> phones = readData<Phone>("phones.txt");

        displayProducts(phones);
    }
    else {
        cout << "Invalid product group!" << endl;
    }
}

int getValidNumberInput(const string& prompt) {
    int number;
    bool isValidInput = false;

    while (!isValidInput) {
        cout << prompt;

        if (cin >> number) {
            isValidInput = true;
        }
        else {
            cout << "Invalid input. Please enter a numerical value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return number;
};


void modifyProduct() {
    cout << "Choose the product group to modify:" << endl;
    cout << "1. Televisions" << endl;
    cout << "2. Phones" << endl;
    cout << "Enter your choice: ";
    int productGroup;
    cin >> productGroup;
    

    if (productGroup == 1) {
        vector<Television*> televisions = readData<Television>("television.txt");
        displayProducts(televisions);


        string newValue;
        //cin >> index;
        int index = getValidNumberInput("Enter the index of the product to modify: ");

        index -= 1;

        // Prompt until a valid index is entered
        while (index < 0 || index >= televisions.size()) {
            cout << "Invalid index. Please enter a value from 1 to " << televisions.size() << ": ";
            cin >> index;
            index -= 1;
        }

        cout << "Enter the attribute index to modify: " << endl << " 1.Name; " << endl << " 2.Price; " << endl << " 3.Description; " << endl << " 4.Model; " << endl << " 5.Screen size; ";
        int attributeIndex = getValidNumberInput("");
        attributeIndex -= 1;
        
        // Prompt until a valid index is entered
        while (attributeIndex < 0 || attributeIndex >= 5) {
            cout << "Invalid index. Please enter a value from 1 to 5 : ";
            cin >> attributeIndex;
            index -= 1;
        }
        cout << "Enter the new value: ";
        cin.ignore();
        getline(cin, newValue);
        modifyAttribute(televisions, index, attributeIndex, newValue);
        writeData(televisions, "television.txt");
    }



    else if (productGroup == 2) {
        vector<Phone*> phones = readData<Phone>("phones.txt");
        // Display the phones for user to choose from

        displayProducts(phones);

        string newValue;
        cout << "Enter the index of the product to modify: ";

        int index = getValidNumberInput("Enter the index of the product to modify: ");
        index -= 1;

        // Prompt until a valid index is entered
        while (index < 0 || index >= phones.size()) {
            cout << "Invalid index. Please enter a value from 1 to " << phones.size() << ": ";
            cin >> index;
            index -= 1;
        }
        cout << "Enter the attribute index to modify: " << endl << " 1.Name; " << endl << " 2.Price; " << endl << " 3.Description; " << endl << " 4.Model; " << endl << " 5.Camera quality; ";


        int attributeIndex = getValidNumberInput("");
        attributeIndex -= 1;
        while (attributeIndex < 0 || attributeIndex >= 5) {
            cout << "Invalid index. Please enter a value from 1 to 5 : ";
            cin >> attributeIndex;
            index -= 1;
        }
        cout << "Enter the new value: ";
        cin.ignore();
        getline(cin, newValue);

        modifyAttribute(phones, index, attributeIndex, newValue);
        writeData(phones, "phones.txt");
    }
    else {
        cout << "Invalid product group!" << endl;
    }

};
void deleteProduct() {
    cout << "Choose the product group to delete from:" << endl;
    cout << "1. Televisions" << endl;
    cout << "2. Phones" << endl;
    cout << "Enter your choice: ";
    int productGroup;
    cin >> productGroup; 
    
    if (productGroup == 1) {
        vector<Television*> televisions = readData<Television>("television.txt");
        if (televisions.empty()) {
            cout << "There are no products to delete." << endl;
        }
        else {
            // Display the televisions for user to choose from
            displayProducts(televisions);

        };

            int index = getValidNumberInput("Enter the index of the product to delete: ");
            index -= 1;


            if (index >= 0 && index < televisions.size()) {
                deleteProductFromFile("television.txt", index + 1);
                // Delete the object from memory
                delete televisions[index];
                televisions.erase(televisions.begin() + index);
                //This removes the element from the vector
                cout << "Product deleted successfully!" << endl;
            }
            else {
                cout << "Invalid index!" << endl;
            }

            writeData(televisions, "television.txt");
        
    }

    else if (productGroup == 2) {
        vector<Phone*> phones = readData<Phone>("phones.txt");
        // Display the phones for user to choose from
        if (phones.empty()) {
            cout << "There are no products to delete." << endl;
        }
        else {
            displayProducts(phones);
            }


            int index = getValidNumberInput("Enter the index of the product to delete: ");
            index--;

            if (index >= 0 && index < phones.size()) {
                deleteProductFromFile("phones.txt", index + 1);
                // Delete the object from memory
                delete phones[index];
                phones.erase(phones.begin() + index);
                //This removes the element from the vector
                cout << "Product deleted successfully!" << endl;
            }
            else {
                cout << "Invalid index!" << endl;
            }

            writeData(phones, "phones.txt");
        
    }
    else {
        cout << "Invalid product group!" << endl;
    }

}
bool isInteger(const string& s) {
    try {
        stoi(s);
        return true;
    }
    catch (const exception&) {
        return false;
    }
};

void addProduct() {
    cout << "Choose the product group to add to:" << endl;
    string whatType;
    cout << "What type of product do you want to add?" << endl << "1.Television" << endl << "2.Phone" << endl;
    cout << "Enter your choice: ";
    cin >> whatType;
    while (!isInteger(whatType)) {
        cout << "Invalid price! Please enter an integer value: ";
        getline(cin, whatType);
    };
    cin.ignore();


    if (whatType == "1") {

        ofstream TelevisionFile("television.txt", ios_base::app);

        Television t;

        string name, price, description, model, screenSize;

        cout << "Enter the name of product : ";
        getline(cin, name);

        cout << "Enter the price of product : ";
        getline(cin, price);
        while (!isInteger(price)) {
            cout << "Invalid price! Please enter an integer value: ";
            getline(cin, price);
        };

        cout << "Enter the description of product : ";
        getline(cin, description);

        cout << "Enter the model of product : ";
        getline(cin, model);

        cout << "Enter the screen size of product : ";
        getline(cin, screenSize);

        t.setName(name);
        t.setPrice(price);
        t.setDescription(description);
        t.setModel(model);
        t.setScreenSize(screenSize);

        t.writeToStream(TelevisionFile);

        TelevisionFile.close();
    }
    else if (whatType == "2") {

        ofstream PhonesFile("phones.txt", ios_base::app);

        Phone p;
        string name, price, description, model, cameraQ;

        cout << "Enter the name of product : ";
        getline(cin, name);

        cout << "Enter the price of product : ";
        getline(cin, price);

        while (!isInteger(price)) {
            cout << "Invalid price! Please enter an integer value: ";
            getline(cin, price);
        };
        cout << "Enter the description of product : ";
        getline(cin, description);

        cout << "Enter the model of product : ";
        getline(cin, model);

        cout << "Enter the camera quality of product : ";
        getline(cin, cameraQ);


        while (!isInteger(cameraQ)) {
            cout << "Invalid camera quality! Please enter an integer value: ";
            getline(cin, cameraQ);
        };;

        p.setName(name);
        p.setPrice(price);
        p.setDescription(description);
        p.setModel(model);
        p.setcameraQuality(cameraQ);

        p.writeToStream(PhonesFile);



        PhonesFile.close();

    }
    else {
        cout << "Invalid product group!" << endl;
    }
}