#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter number of items (n): ";
    cin >> n;

    vector<int> items(n);
    cout << "Enter initial items row:\n";
    for (int i = 0; i < n; i++) {
    cout << "Item " << i + 1 << ": ";
    cin >> items[i];
}

    long long h;
    cout << "Enter number of hours (h): ";
    cin >> h;

    // Effective shift using modulo operator
    int shift = h % n;

    cout << "Final display order: ";
    for (int i = 0; i < n; i++) {
        cout << items[(i + shift) % n] << " ";
    }
    cout << endl;

    return 0;
}