#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cout << "Enter number of borrow records: ";
    cin >> n;

    vector<int> log(n);
    cout << "Enter book IDs in borrowing log: ";
    for (int i = 0; i < n; i++) {
        cin >> log[i];
    }

    // Frequency map to store borrow counts
    unordered_map<int, int> counts;
    for (int id : log) {
        counts[id]++;
    }

    cout << "Books needing priority restocking: ";
    for (const auto& pair : counts) {
        if (pair.second > 1) {
            cout << pair.first << " ";
        }
    }
    cout << endl;

    return 0;
}