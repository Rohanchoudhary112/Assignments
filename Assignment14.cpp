#include <iostream>
#include <string>
using namespace std;
class StringAnalyzer {
private:
    string str;
public:
    StringAnalyzer(const string& s) : str(s) {}
    int calculateTotalWords() const {
        int count = 0;
        bool inWord = false;
        for (char c : str) {
            if (c == ' ' || c == '\t' || c == '\n') {
                inWord = false;
            } else if (!inWord) {
                count++;
                inWord = true;
            }
        }
        return count;
    }
};
int main() {
    string inputString = "Hello I Am Rohan Choudhary.";
    StringAnalyzer analyzer(inputString);
    int totalWords = analyzer.calculateTotalWords();
    cout << "Total words in the string: " << totalWords << endl;
    return 0;
}
