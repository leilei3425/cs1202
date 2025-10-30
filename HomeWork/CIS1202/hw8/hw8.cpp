// hw8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Lei Zhang
//CIS 1202 803
//March 25, 2025


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Structure for a transaction
struct Transaction {
    string name;
    float amount;
};

// Structure for a bank account
struct Account {
    string owner;
    int accountNumber;
    float balance;
    Transaction transactions[100];
    int transactionCount;
};

// Function prototypes
void initializeAccount(Account&);
void addTransaction(Account&);
void displayTransactions(const Account&);
void searchTransaction(const Account&, const string&);
void sortTransactions(Account&);

int main() {
    Account account;
    initializeAccount(account);

    int choice;
    string searchName;

    do {
        cout << "\nBank Checking Account System" << endl;
        cout << "1. Add Transaction" << endl;
        cout << "2. Display Transactions" << endl;
        cout << "3. Search Transaction" << endl;
        cout << "4. Sort Transactions by Amount" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addTransaction(account);
            break;
        case 2:
            displayTransactions(account);
            break;
        case 3:
            cout << "Enter transaction name to search: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, searchName);
            searchTransaction(account, searchName);
            break;
        case 4:
            sortTransactions(account);
            cout << "Transactions sorted by amount." << endl;
            break;
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

// Function to initialize account
void initializeAccount(Account& account) {
    account.balance = 0.0;
    account.transactionCount = 0;

    cout << "Enter account owner name: ";
    getline(cin, account.owner);
    cout << "Enter account number: ";
    cin >> account.accountNumber;

    cout << "Enter initial balance: ";
    cin >> account.balance;
}

// Function to add a transaction
void addTransaction(Account& account) {
    if (account.transactionCount >= 100) {
        cout << "Transaction limit reached! Cannot add more transactions." << endl;
        return;
    }

    Transaction newTransaction;
    cout << "Enter transaction name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer
    getline(cin, newTransaction.name);
    cout << "Enter transaction amount: ";
    cin >> newTransaction.amount;

    account.transactions[account.transactionCount] = newTransaction;
    account.transactionCount++;
    account.balance -= newTransaction.amount;
    cout << "Transaction added successfully!" << endl;
}

// Function to display all transactions
void displayTransactions(const Account& account) {
    if (account.transactionCount == 0) {
        cout << "No transactions to display." << endl;
        return;
    }

    cout << "\nTransactions List:" << endl;
    cout << left << setw(20) << "Name" << setw(10) << "Amount" << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < account.transactionCount; i++) {
        cout << left << setw(20) << account.transactions[i].name << "$" << fixed << setprecision(2) << account.transactions[i].amount << endl;
    }
    cout << "Current Balance: $" << fixed << setprecision(2) << account.balance << endl;
}

// Function to search for a transaction by name
void searchTransaction(const Account& account, const string& searchName) {
    bool found = false; // set a flag if no found
    for (int i = 0; i < account.transactionCount; i++) {
        if (account.transactions[i].name == searchName) {
            cout << "\nFound transaction:" << endl;
            cout << left << setw(20) << "Name" << setw(10) << "Amount" << endl;
            cout << "------------------------------" << endl;
            cout << left << setw(20) << account.transactions[i].name << "$" << fixed << setprecision(2) << account.transactions[i].amount << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Transaction not found." << endl; // Not found
    }
}

// Function to sort transactions by amount using selection sort
void sortTransactions(Account& account) {
    for (int i = 0; i < account.transactionCount - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < account.transactionCount; j++) {
            if (account.transactions[j].amount < account.transactions[minIndex].amount) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(account.transactions[i], account.transactions[minIndex]);
        }
    }
}