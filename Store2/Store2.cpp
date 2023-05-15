#include "Authorization.h"
#include "Product.h"
#include "Television.h"
#include "Phone.h"
#include <iostream>
//#include  <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>
#include  <sstream>
using namespace std;


void check(string &str) {
    while (str.find_first_not_of("0123456789") != string::npos) {
        cout << "Not integer!";
        cin.ignore();
        cin >> str;
    };
   
}; 
template<typename T>

vector<T*> readData(const string& filename) {
    ifstream fileRead(filename);
    if (!fileRead.is_open()) {
        cout << "Error opening file!" << endl;
    }
    int numObjects = 0;
    string line;
    while (getline(fileRead, line)) {
        ++numObjects;
    }
    fileRead.clear();
    fileRead.seekg(0, ios::beg);
    vector<T*> productsTel(numObjects);
    for (int i = 0; i < numObjects; ++i) {
        string name;
        string price;
        string description;
        string model;
        string additionalAttribute;
        getline(fileRead, name, ',');
        getline(fileRead, price, ',');
        getline(fileRead, description, ',');
        getline(fileRead, model, ',');
        getline(fileRead, additionalAttribute);

        productsTel[i] = new T(name, price, description, model, additionalAttribute);
    }

    fileRead.close();

    return productsTel;
};

template<typename T>
void modifyAttribute(vector<T*>& products, int index, int attributeIndex, const string& newValue) {
    if (index >= 0 && index < products.size()) {
        T* product = products[index];
        switch (attributeIndex) {
        case 0:
            product->setName(newValue);
            break;
        case 1:
            product->setPrice(newValue);
            break;
        case 2:
            product->setDescription(newValue);
            break;
        case 3:
            product->setModel(newValue);
            break;
        case 4:
            product->setAdditionalAttribute(newValue);
            break;
        default:
            cout << "Invalid attribute index!" << endl;
            break;
        }
    }
    else {
        cout << "Invalid index!" << endl;
    }
}

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

template<typename T>
void writeData(const vector<T*>& products, const string& filename) {
    // Clear the file
    ofstream clearFile(filename, ofstream::out | ofstream::trunc);
    if (!clearFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    };
    clearFile.close();

    ofstream fileWrite(filename);
    if (!fileWrite.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    for (const T* product : products) {
        product->writeToStream(fileWrite);
    }
    fileWrite.close();
}


int main()
{

    //string password, userName;
    //cout << "User name:" << endl;
    //cin >> userName;
    //cout << "Password:" << endl;
    //cin >> password;
    //Authorization logIn(password, userName);

    //if (logIn.checkLogIn(userName, password) == true) {
    //    cout << "Login was successful!";
    //}
    //else {
    //    cout << "Wrong password or username! Try again!";
    //    return 0; // Exit the program if login fails
    //}

    cout << "**********************************************" << endl;
    cout << "*                  WELCOME                   *" << endl;
    cout << "*           TO ELECTRONIC STORE!             *" << endl;
    cout << "*                                            *" << endl;
    cout << "**********************************************" << endl;
    cout << endl;

    int choice;
    while (true) {
        cout << "Menu Options:" << endl;
        cout << "1. Display All Products" << endl;
        cout << "2. Modify Product" << endl;
        cout << "3. Delete Product" << endl;
        cout << "4. Add Product" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter an integer." << endl;
            // Clear the input stream
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
        case 1: {
            cout << "Choose the product group to display:" << endl;
            cout << "1. Televisions" << endl;
            cout << "2. Phones" << endl;
            cout << "Enter your choice: ";
            int productGroup;
            
            if (!(cin >> productGroup)) {
                cout << "Invalid input. Please enter an integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (productGroup == 1) {
                vector<Television*> televisions = readData<Television>("television.txt");
                for (int i = 0; i < televisions.size(); ++i) {
                    const auto& product = televisions[i];
                    cout << i + 1 << ". "
                        << "Name: " << product->getName() << endl
                        << "Price: " << product->getPrice() << endl
                        << "Description: " << product->getDescription() << endl
                        << "Model: " << product->getModel() << endl
                        << "Screen Size: " << product->getScreenSize() << endl
                        << endl;
                    cout << endl;
                }
            }
            else if (productGroup == 2) {
                vector<Phone*> phones = readData<Phone>("phones.txt");

                for (int i = 0; i < phones.size(); ++i) {
                    const auto& product = phones[i];
                    cout << i + 1 << ". "
                        << "Name: " << product->getName() << endl
                        << "Price: " << product->getPrice() << endl
                        << "Description: " << product->getDescription() << endl
                        << "Model: " << product->getModel() << endl
                        << "Camera quality: " << product->getcameraQuality() << endl
                        << endl;
                    cout << endl;
                }
            }
            else {
                cout << "Invalid product group!" << endl;
            }

            break;
        }
        case 2: {
            cout << "Choose the product group to modify:" << endl;
            cout << "1. Televisions" << endl;
            cout << "2. Phones" << endl;
            cout << "Enter your choice: ";
            int productGroup;
            if (!(cin >> productGroup)) {
                cout << "Invalid input. Please enter an integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            };
            while (productGroup < 0 || productGroup >= 2) {
                cout << "Invalid index. Please enter a value from 1 to  2 : ";
                cin >> productGroup;
            }

            if (productGroup == 1) {
                vector<Television*> televisions = readData<Television>("television.txt");
                // Display the televisions for user to choose from
                for (int i = 0; i < televisions.size(); ++i) {
                    const auto& product = televisions[i];
                    cout << i + 1 << ". "
                        << "Name: " << product->getName() << endl
                        << "Price: " << product->getPrice() << endl
                        << "Description: " << product->getDescription() << endl
                        << "Model: " << product->getModel() << endl
                        << "Screen Size: " << product->getScreenSize() << endl
                        << endl;
                    cout << endl;
                }


                int index, attributeIndex;
                string newValue;
                cout << "Enter the index of the product to modify: ";
                cin >> index;
                index -= 1;

                // Prompt until a valid index is entered
                while (index < 0 || index >= televisions.size()) {
                    cout << "Invalid index. Please enter a value from 1 to " << televisions.size() << ": ";
                    cin >> index;
                    index -= 1;
                }
      
                cout << "Enter the attribute index to modify: "<<endl<<" 1.Name; " << endl << " 2.Price; " << endl << " 3.Description; " << endl << " 4.Model; " << endl << " 5.Screen size; ";
                cin >> attributeIndex;
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

                for (int i = 0; i < phones.size(); ++i) {
                    const auto& product = phones[i];
                    cout << i + 1 << ". "
                        << "Name: " << product->getName() << endl
                        << "Price: " << product->getPrice() << endl
                        << "Description: " << product->getDescription() << endl
                        << "Model: " << product->getModel() << endl
                        << "Camera quality: " << product->getcameraQuality() << endl
                        << endl;
                    cout << endl;
                }

                int index, attributeIndex;
                string newValue;
                cout << "Enter the index of the product to modify: ";
               
                if (!(cin >> index)) {
                    cout << "Invalid input. Please enter an integer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                index -= 1;

                // Prompt until a valid index is entered
                while (index < 0 || index >= phones.size()) {
                    cout << "Invalid index. Please enter a value from 1 to " << phones.size() << ": ";
                    cin >> index;
                    index -= 1;
                }
                cout << "Enter the attribute index to modify: " << endl << " 1.Name; " << endl << " 2.Price; " << endl << " 3.Description; " << endl << " 4.Model; " << endl << " 5.Camera quality; ";
                

                if (!(cin >> attributeIndex)) {
                    cout << "Invalid input. Please enter an integer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
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

            break;
        }
        case 3: {
            cout << "Choose the product group to delete from:" << endl;
            cout << "1. Televisions" << endl;
            cout << "2. Phones" << endl;
            cout << "Enter your choice: ";
            int productGroup;
            if (!(cin >> productGroup)) {
                cout << "Invalid input. Please enter an integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            };
            if (productGroup == 1) {
                vector<Television*> televisions = readData<Television>("television.txt");
                if (televisions.empty()) {
                    cout << "There are no products to delete." << endl;
                }
                else {
                    // Display the televisions for user to choose from
                    for (int i = 0; i < televisions.size(); ++i) {
                        const auto& product = televisions[i];
                        cout << i + 1 << ". "
                            << "Name: " << product->getName() << endl
                            << "Price: " << product->getPrice() << endl
                            << "Description: " << product->getDescription() << endl
                            << "Model: " << product->getModel() << endl
                            << "Screen Size: " << product->getScreenSize() << endl
                            << endl;
                        cout << endl;
                    };

                    int index;
                    cout << "Enter the index of the product to delete: ";
                    if (!(cin >> index)) {
                        cout << "Invalid input. Please enter an integer." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    index -= 1;


                    if (index >= 0 && index < televisions.size()) {
                        deleteProductFromFile("television.txt", index + 1);
                        // Delete the object from memory
                        delete televisions[index];
                        televisions.erase(televisions.begin() + index);
                        cout << "Product deleted successfully!" << endl;
                    }
                    else {
                        cout << "Invalid index!" << endl;
                    }

                    writeData(televisions, "television.txt");
                }
            }

            else if (productGroup == 2) {
                vector<Phone*> phones = readData<Phone>("phones.txt");
                // Display the phones for user to choose from
                if (phones.empty()) {
                    cout << "There are no products to delete." << endl;
                }
                else {
                    for (int i = 0; i < phones.size(); ++i) {
                        const auto& product = phones[i];
                        cout << i + 1 << ". "
                            << "Name: " << product->getName() << endl
                            << "Price: " << product->getPrice() << endl
                            << "Description: " << product->getDescription() << endl
                            << "Model: " << product->getModel() << endl
                            << "Camera quality: " << product->getcameraQuality() << endl
                            << endl;
                        cout << endl;
                    }

                    int index;
                    cout << "Enter the index of the product to delete: ";
                    if (!(cin >> index)) {
                        cout << "Invalid input. Please enter an integer." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    index--;

                    if (index >= 0 && index < phones.size()) {
                        deleteProductFromFile("phones.txt", index + 1);
                        // Delete the object from memory
                        delete phones[index];
                        phones.erase(phones.begin() + index);
                        cout << "Product deleted successfully!" << endl;
                    }
                    else {
                        cout << "Invalid index!" << endl;
                    }

                    writeData(phones, "phones.txt");
                }
            }
            else {
                cout << "Invalid product group!" << endl;
            }
        

            break;
        }case 4: {
            cout << "Choose the product group to add to:" << endl;
            string whatType;
           cout << "What type of product do you want to add?" << endl <<"1.Television"<< endl << "2.Phone"<<endl;
            cout << "Enter your choice: ";
            cin >> whatType;
            check(whatType);
            cin.ignore();

           


            if (whatType == "1") {

               ofstream TelevisionFile("television.txt", ios_base::app);

               Television t;

               string name, price, description, model, screenSize;

               cout << "Enter the name of product : ";
               cin.ignore();
               getline(cin, name);

               cout << "Enter the price of product : ";
               getline(cin, price);
               check(price);
                cin.ignore();
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
               cin.ignore();
               getline(cin, name);

               cout << "Enter the price of product : ";
               getline(cin, price);
               check(price);
               cin.ignore();
               cout << "Enter the description of product : ";
               getline(cin, description);

               cout << "Enter the model of product : ";
               getline(cin, model);

               cout << "Enter the camera quality of product : ";
               getline(cin, cameraQ);

               check(cameraQ);

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

            break;
        }
        }

    }
}
