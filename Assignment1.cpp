#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Account {
    int id;
    string password;
    double balance;
};
vector<Account> accounts;
void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();
void printIntroMenu() {
    cout << "Please select an option from the menu below:\n"
         << "l -> Login\n"
         << "c -> Create New Account\n"
         << "q -> Quit\n"
         << "> ";
}
void printMainMenu() {
    cout << "d -> Deposit Money\n"
         << "w -> Withdraw Money\n"
         << "r -> Request Balance\n"
         << "q -> Quit\n"
         << "> ";
}
void login() {
    int id;
    string password;
    bool found = false;
    cout << "Please enter your user id: ";
    cin >> id;
    cout << "Please enter your password: ";
    cin >> password;
    for (const auto& account : accounts) {
        if (account.id == id && account.password == password) {
            found = true;
            cout << "Access Granted!\n";
            printMainMenu(); // Prompt for the main menu options
            char choice;
            cin >> choice;
            while (choice != 'q') {
                switch (choice) {
                    case 'd': {
                        double amount;
                        cout << "Amount of deposit: $";
                        cin >> amount;
                        for (auto& acc : accounts) {
                            if (acc.id == id) {
                                acc.balance += amount;
                                break;
                            }
                        }
                        cout << "Deposit successful.\n";
                        printMainMenu();
                        cin >> choice;
                        break;
                    }
                    case 'w': {
                        double amount;
                        cout << "Amount of withdrawal: $";
                        cin >> amount;
                        for (auto& acc : accounts) {
                            if (acc.id == id) {
                                if (acc.balance >= amount) {
                                    acc.balance -= amount;
                                    cout << "Withdrawal successful.\n";
                                } else {
                                    cout << "Insufficient balance.\n";
                                }
                                break;
                            }
                        }
                        printMainMenu();
                        cin >> choice;
                        break;
                    }
                    case 'r': {
                        for (const auto & acc : accounts) {
                            if (acc.id == id) {
                                cout << "Your balance is $" << acc.balance << ".\n";
                                break;
                            }
                        }
                        printMainMenu();
                        cin >> choice;
                        break;
                    }
                    default:
                        cout << "Invalid choice. Please try again.\n";
                        printMainMenu();
                        cin >> choice;
                        break;
                }
            }
            return; // Return after handling login
        }
    }
    if (!found) {
        cout << "******** LOGIN FAILED! ********\n";
        printIntroMenu();
    }
}
void createAccount() {
    Account newAccount;
    cout << "Please enter your user id: ";
    cin >> newAccount.id;
    cout << "Please enter your password: ";
    cin >> newAccount.password;
     newAccount.balance = 0.0;
    cout << "Thank You! Your account has been created!\n";
    accounts.push_back(newAccount); // Add the newly created account to the vector
    printIntroMenu();
}
void start() {
    char choice;
    printIntroMenu();
    cin >> choice;
    while (choice != 'q') {
        switch (choice) {
            case 'l':
                login();
                break;
            case 'c':
                createAccount();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                printIntroMenu();
                break;
        }
        cin >> choice; // Read choice again after each action
    }
}
int main() {
    start();
    cout << "Thanks for using the ATM!\n";
    return 0;
}