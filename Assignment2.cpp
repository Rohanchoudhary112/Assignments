#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class GuessTheNumber {
private:
    int computerGeneratedNumber;
    int userGuessedNumber;
    int attempts;
public:
    GuessTheNumber() {
        srand(time(nullptr));
        generateRandomNumber();
        attempts = 0;
    }
    void generateRandomNumber() {
        computerGeneratedNumber = rand() % 100 + 1;
    }
    void startGame() {
        cout << "Guess the number: ";
        cin >> userGuessedNumber;
        attempts++;
        while (userGuessedNumber != computerGeneratedNumber) {
            if (userGuessedNumber < computerGeneratedNumber) {
                cout << "Attempt: " << attempts << endl;
                cout << "Message: Guessed number is smaller than computer generated number" << endl;
            } else {
                cout << "Attempt: " << attempts << endl;
                cout << "Message: Guessed number is greater than computer generated number" << endl;
            }
            cout << "Guess the number: ";
            cin >> userGuessedNumber;
            attempts++;
        }
        cout << "Attempt: " << attempts << endl;
        cout << "Message: Congratulations, you won the game in " << attempts << " attempts" << endl;
    }
};
int main() {
    GuessTheNumber game;
    game.startGame();
    return 0;
}
