#include <iostream>
#include <vector>

using namespace std;

// 1. Iterative Binary Search (Librarian uses a loop)
int binarySearchIterative(const vector<int>& books, int target) {
    int low = 0;
    int high = books.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (books[mid] == target) {
            return mid; // Target found
        }
        else if (books[mid] < target) {
            low = mid + 1; // Search right half
        }
        else {
            high = mid - 1; // Search left half
        }
    }
    return -1; // Not found
}

// 2. Recursive Binary Search (Librarian calls itself on half-catalog)
int binarySearchRecursive(const vector<int>& books, int target, int low, int high) {
    if (low > high) {
        return -1; // Base Case: Search space exhausted
    }

    int mid = low + (high - low) / 2;

    if (books[mid] == target) {
        return mid; // Base Case: Target found
    }
    else if (books[mid] < target) {
        return binarySearchRecursive(books, target, mid + 1, high); // Search right
    }
    else {
        return binarySearchRecursive(books, target, low, mid - 1); // Search left
    }
}

int main() {
    int n;
    cout << "Enter number of books (sorted order): ";
    cin >> n;

    vector<int> books(n);
    cout << "Enter sorted book codes: ";
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    int target;
    cout << "Enter target book code to search: ";
    cin >> target;

    int posIterative = binarySearchIterative(books, target);
    int posRecursive = binarySearchRecursive(books, target, 0, n - 1);

    cout << "\n--- SEARCH RESULTS ---" << endl;
    if (posIterative != -1) {
        cout << "[Iterative] Target book code found at index (0-based): " << posIterative << endl;
        cout << "[Recursive] Target book code found at index (0-based): " << posRecursive << endl;
    } else {
        cout << "Target book code not found in the catalog." << endl;
    }

    return 0;
}