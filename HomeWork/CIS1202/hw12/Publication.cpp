// Publication.cpp
#include <iostream>
#include "Publication.h"

Publication::Publication()
    : title(""), publisher(""), price(0.0), year(0), type(BOOK), stock(0) {
}


void Publication::storePublication(string itemTitle, string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock) {
    title = itemTitle;
    publisher = itemPublisher;
    price = itemPrice;
    year = itemYear;
    type = itemType;
    stock = itemStock;
}

void Publication::displayInfo() {
    // display all publication info
    cout << "The title is: " << title << endl;
    cout << publisher << endl;
    cout << "Price: $" << price << endl;
    cout << year << endl;
    // check media type and display
    switch (type) {
    case BOOK: cout << "Book"; break;
    case MAGAZINE: cout << "Magazine"; break;
    case NEWSPAPER: cout << "Newspaper"; break;
    case AUDIO: cout << "Audio"; break;
    case VIDEO: cout << "Video"; break;
    }
    cout << endl;
    cout << "Stock: " << stock << endl;
}

void Publication::checkOut() {
    // decrease stock for checkout
    if (stock > 0) {
        stock--;
        
    }
    else {
        cout << "Out of stock!" << endl;
    }
}

void Publication::checkIn() {
    // increase stock for checkin
    stock++;
   
}

string Publication::getTitle() {
    //return title
    return title;
}

int Publication::getStock() {
    // get stock num
    return stock;
}