#include <iostream>
using namespace std;

int main() {
    int size = 10;
    int table[10];

    for (int i = 0; i < size; i++)
        table[i] = -1;

    int ids[] = {23, 43, 13, 27, 37, 47};
    int n = 6;

    for (int i = 0; i < n; i++) {
        int id = ids[i];

        int index = id % size;          // First hash function
        int jump = 7 - (id % 7);        // Second hash function

        int count = 0;

        while (table[index] != -1 && count < size) {
            index = (index + jump) % size;
            count++;
        }

        if (count < size && table[index] == -1)
            table[index] = id;
        else
            cout << "No slot available for " << id << endl;
    }

    cout << "\nFinal Hash Table:\n";
    for (int i = 0; i < size; i++) {
        cout << "Slot " << i << ": ";
        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];
        cout << endl;
    }
    return 0;
}
