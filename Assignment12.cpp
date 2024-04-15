#include <iostream>
using namespace std;
class largerUnit;
class smallUnit {
private:
    double inches;
public:
    smallUnit(double in) : inches(in) {}
    double getInches() const { return inches; }
    operator largerUnit() const;
};
class largerUnit {
private:
    double feet;
public:
    largerUnit() : feet(0) {}
    largerUnit(const smallUnit& su) : feet(su.getInches() / 12.0) {}
    largerUnit(double ft) : feet(ft) {}
    void display() const {
        cout << "Measurement in feet: " << feet << endl;
        cout << "Measurement in inches: " << feet * 12 << endl;
    }
};
smallUnit::operator largerUnit() const {
    return largerUnit(inches / 12.0);
}
int main() {
    smallUnit small(24);
    largerUnit large = small;
    large.display();
    return 0;
}