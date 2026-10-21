#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int SIZE = 10;

int main() {
    vector<list<int>> shelves(SIZE);

    int n, code;

    cout << "Enter number of book codes: ";
    cin >> n;

    cout << "Enter book codes:\n";

    for (int i = 0; i < n; i++) {
        cin >> code;

        int shelf = code % SIZE;
        shelves[shelf].push_back(code);

        cout << "Book " << code
             << " added to shelf " << shelf << "\n";
    }

    cout << "\nFinal Shelf Contents:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << "Shelf " << i << ": ";

        if (shelves[i].empty()) {
            cout << "Empty";
        } else {
            for (int book : shelves[i]) {
                cout << book << " -> ";
            }
            cout << "NULL";
        }

        cout << "\n";
    }

    return 0;
}
