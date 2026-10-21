#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

int main() {
    string slots[SIZE];

    for (int i = 0; i < SIZE; i++) {
        slots[i] = "";
    }

    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string reg;
        cout << "Enter registration number: ";
        cin >> reg;

        // Last digit determines the initial slot
        int index = reg.back() - '0';
        int checked = 0;

        // Linear probing with wrap-around
        while (checked < SIZE && slots[index] != "") {
            index = (index + 1) % SIZE;
            checked++;
        }

        if (checked == SIZE) {
            cout << "Parking lot is full. Vehicle "
                 << reg << " cannot be parked.\n";
        } else {
            slots[index] = reg;
            cout << "Vehicle " << reg
                 << " parked at slot " << index << "\n";
        }
    }

    cout << "\nFinal Parking Lot:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Slot " << i << ": ";
        if (slots[i] == "")
            cout << "Empty";
        else
            cout << slots[i];
        cout << "\n";
    }

    return 0;
}
