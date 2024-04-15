#include <iostream>
using namespace std;
class Matrix {
private:
    int data[3][3];
public:
    Matrix() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                data[i][j] = 0;
            }
        }
    }
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    void set(int i, int j, int value) {
        data[i][j] = value;
    }
    void display() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Matrix OBJ1, OBJ2;
    Matrix OBJ3 = OBJ1 + OBJ2;
    cout << "Result of matrix addition:" << endl;
    OBJ3.display();
    return 0;
}
