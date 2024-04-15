#include <iostream>
#include <string>
using namespace std;
class MenuItem {
protected:
    string name;
    double price;
public:
    MenuItem(const string& name, double price) : name(name), price(price) {}
    virtual void display() const = 0;
    double getPrice() const { return price; }
    const string& getName() const { return name; }
};
class IndianFoodItem : public MenuItem {
public:
    IndianFoodItem(const string& name, double price)
        : MenuItem(name, price) {}
    void display() const override {
        cout << "Name: " << getName() << ", Price: $" << getPrice() << endl;
    }
};
class BillingSystem {
private:
    MenuItem* items[10];
    int count;
public:
    BillingSystem() : count(0) {}
    void addItem(MenuItem* item) { if (count < 10) items[count++] = item; }
    double calculateTotal() const { double total = 0; for (int i = 0; i < count; ++i) total += items[i]->getPrice(); return total; }
    void printBill() const { for (int i = 0; i < count; ++i) items[i]->display();cout << "Total: $" << calculateTotal() << endl; }
};
int main() {
    IndianFoodItem biryani("Chicken Biryani",  500);
    IndianFoodItem curry("Vegetable Curry",  300);
    BillingSystem bill;
    bill.addItem(&biryani);
    bill.addItem(&curry);
    bill.printBill();
    return 0;
}
