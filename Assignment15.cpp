#include <iostream>
using namespace std;
class ClassB;
class ClassA {
private:
    int a;
public:
    ClassA(int a_val) : a(a_val) {}
    friend int sumPrivateMembers(const ClassA& objA, const ClassB& objB);
};
class ClassB {
private:
    int b;
public:
    ClassB(int b_val) : b(b_val) {}
    friend int sumPrivateMembers(const ClassA& objA, const ClassB& objB);
};
int sumPrivateMembers(const ClassA& objA, const ClassB& objB) {
    return objA.a + objB.b;
}
int main() {
    ClassA objA(5);
    ClassB objB(10);
    int total = sumPrivateMembers(objA, objB);
    cout << "Sum of private members: " << total << endl;
    return 0;
}
