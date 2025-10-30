// hw13.cpp : This file contains the 'main' function. Program execution begins and ends there.
// hw12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Lei Zhang
//CIS 1202 803
//April 19

#include <iostream>
#include <fstream>
#include "Publication.h"

using namespace std;

void getPublicationInfo(Publication& pub) {
    string title, publisher;
    double price;
    int year, stock, typeChoice;

    cout << "Title: ";
    getline(cin, title);

    cout << "Publisher: ";
    getline(cin, publisher);

    cout << "Price: ";
    cin >> price;

    cout << "Year: ";
    cin >> year;

    cout << "1.Book /  2.Magazine  3.Newspaper / 4.Audio / 5.Video" << endl << "Type: ";
    cin >> typeChoice;

    cout << "Stock: ";
    cin >> stock;



    //casting an int (typeChoice) into PublicationType enum
    PublicationType type = static_cast<PublicationType>(typeChoice - 1);

    pub.storePublication(title, publisher, price, year, type, stock);
}


// Function prototypes
void getPublications(Publication[], int&);
void showPublications(Publication[], int);
void showTitles(Publication[], int);
int findPublication(Publication[], int, string);
int getMenuChoice();

const int MAX_PUBLICATIONS = 100;

int main() {

    //creat a lis of publication
    Publication publications[MAX_PUBLICATIONS];
    int count;
    getPublications(publications, count);
    string title;

    int choice; // User menu selection
    int item_index;
    do {
        choice = getMenuChoice();

        switch (choice) {
        case 1:
            showPublications(publications, count);
            break;

        case 2:
            showTitles(publications, count);
            break;

        case 3:
            findPublication(publications, count, title);
            break;
        case 4:
            // check out
            item_index = findPublication(publications, count, title);
            // check if no  found
            if (item_index == -1) {
                // not found
                cout << "Item not found!" << endl;
            }
            else {
                // find it -> checkout
                publications[item_index].checkOut();
                cout << "\nAfter checkout" << endl;
                publications[item_index].displayInfo();
            }
            break;
        case 5:
            // check in
            item_index = findPublication(publications, count, title);
            // check if no  found
            if (item_index == -1) {
                // not found
                cout << "Item not found!" << endl;
            }
            else {
                // find it -> checkin
                publications[item_index].checkIn();
                cout << "\nAfter checkin" << endl;
                publications[item_index].displayInfo();
            }
            break;

        case 6:
            return 0; // Exit program

        default:
            cout << "Invalid selection. Please enter a number 1-6: \n";
            break;
        }
    } while (choice != 6);


    return 0;
}

void getPublications(Publication publications[], int& count) {

    ifstream inputFile("publications.txt");
    if (!inputFile) {
        cerr << "Error opening file.\n";
        count = 0;
        return;
    }

    string title, publisher;
    double price;
    int year, typeInt, stock;
    count = 0;

    while (getline(inputFile, title)) {
        getline(inputFile, publisher);
        inputFile >> price;
        inputFile >> year;
        inputFile >> typeInt;
        inputFile >> stock;
        inputFile.ignore(); // skip the newline after stock

        publications[count].storePublication(title, publisher, price, year,
            static_cast<PublicationType>(typeInt), stock);
        count++;
    }

    inputFile.close();

};

void showPublications(Publication publications[], int count) {
    for (int i = 0;i < count;i++) {
        publications[i].displayInfo();
    }
};

void showTitles(Publication publications[], int count) {

    for (int i = 0;i < count;i++) {
        cout << publications[i].getTitle() << endl;

    }
};

int findPublication(Publication publications[], int count, string title) {
    cout << "Publication Title?";

    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // input name with space
    getline(cin, title);
    int item_index = -1;
    for (int i = 0;i < count;i++) {
        if (publications[i].getTitle() == title) {
            //print publication
            publications[i].displayInfo();
            item_index = i;
        }
    }

    return item_index;
};

int getMenuChoice() {
    int choice = 0;//Declare an variable to store user input

    cout << "1. Display all publications" << endl;
    cout << "2. Display publication titles" << endl;
    cout << "3. Find a publication" << endl;
    cout << "4. Check out" << endl;
    cout << "5. Check in" << endl;
    cout << "6. Exit" << endl;

    cin >> choice;

    if (choice >= 1 && choice <= 6) {
        return choice;
    }
    // invalid input
    else {
        return -1;
    }

}




