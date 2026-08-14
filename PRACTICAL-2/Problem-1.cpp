#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. Iterative Linear Search (Guard checks sequentially using a loop)
int linearSearchIterative(const vector<string>& plates, const string& target) {
    for (int i = 0; i < plates.size(); i++) {
        if (plates[i] == target) {
            return i; // Returns index of the first occurrence
        }
    }
    return -1; // Not found
}

// 2. Recursive Linear Search (Guard calls helper/itself to check next plate)
int linearSearchRecursive(const vector<string>& plates, const string& target, int index) {
    // Base Case 1: End of list reached
    if (index >= plates.size()) {
        return -1;
    }
    // Base Case 2: Target found
    if (plates[index] == target) {
        return index;
    }
    // Recursive Case: Check next position
    return linearSearchRecursive(plates, target, index + 1);
}

int main() {
    int n;
    cout << "Enter number of license plates: ";
    cin >> n;

    vector<string> plates(n);
    cout << "Enter license plates: ";
    for (int i = 0; i < n; i++) {
        cin >> plates[i];
    }

    string target;
    cout << "Enter target license plate to find: ";
    cin >> target;

    // Running Iterative Approach
    int posIterative = linearSearchIterative(plates, target);
    
    // Running Recursive Approach
    int posRecursive = linearSearchRecursive(plates, target, 0);

    cout << "\n--- SEARCH RESULTS ---" << endl;
    if (posIterative != -1) {
        cout << "[Iterative] Target plate found at index (0-based): " << posIterative << endl;
        cout << "[Recursive] Target plate found at index (0-based): " << posRecursive << endl;
    } else {
        cout << "Target plate not found in the list." << endl;
    }

    return 0;
}
