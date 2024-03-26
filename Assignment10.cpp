#include <iostream>
#include <string>
using namespace std;
const int MAX_BOOKS = 5;
struct Book {
    string isbn;
    string title;
    string author;
    int year;
};
int main() {
    Book library[MAX_BOOKS] = {
        {"1", "Mobile Computing", "K Nath & Sons, Meerut", 2011},
        {"2", "Data Structure Using C", "Thakur Publications Lucknow", 2015},
        {"3", "Client Server Computing","Sun India Publications,New Delhi", 2012},
        {"4", "Computer Networks", "Sun India Publication, New Delhi ", 2010},
        {"5", "Computer Networks 2", "Thakur Publications", 2016}
    };
    cout << "Enter the ISBN of the book: ";
    string isbn;
    cin >> isbn;
    bool found = false;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        if (library[i].isbn == isbn) {
            cout << "Book found in the library." << endl;
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "Year: " << library[i].year << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book Not Found...." << endl;
    }
    return 0;
}
