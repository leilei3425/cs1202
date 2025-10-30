// hw12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Lei Zhang
//CIS 1202 803
//April 19

#include <iostream>
#include "Publication.h"

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

int main() {
    //creat a publication
    Publication pub;

    getPublicationInfo(pub);

    cout << "\nStored publication: " << pub.getTitle() << endl;

    pub.checkOut();
    cout << pub.getStock() << " in stock after check out" << endl;

    pub.checkIn();
    cout << pub.getStock() << "in stock after check in" << endl;


    pub.displayInfo();

    return 0;
}

