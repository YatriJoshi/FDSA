#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);
    string word;
    string longestWord = "";

    while (ss >> word) {
        // Strict greater-than retains the first encountered longest word
        if (word.length() > longestWord.length()) {
            longestWord = word;
        }
    }

    cout << "Winning word: " << longestWord << endl;
    cout << "Letter count: " << longestWord.length() << endl;

    return 0;
}