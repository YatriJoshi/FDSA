#include <iostream>
using namespace std;

class TrayStack {
private:
    int* arr;
    int capacity;
    int top;

public:
    TrayStack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~TrayStack() {
        delete[] arr;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void placeTray(int trayID) {
        if (isFull()) {
            cout << "Error: Counter is FULL! Cannot place tray " << trayID << ".\n";
            return;
        }
        arr[++top] = trayID;
        cout << "Placed tray " << trayID << ". Current top tray: " << arr[top] << "\n";
    }

    void takeTray() {
        if (isEmpty()) {
            cout << "Error: Counter is EMPTY! No tray to take.\n";
            return;
        }
        cout << "Took tray " << arr[top--] << ". ";
        if (!isEmpty()) {
            cout << "Current top tray: " << arr[top] << "\n";
        } else {
            cout << "Counter is now empty.\n";
        }
    }
};

int main() {
    TrayStack counter(3);
    counter.placeTray(101);
    counter.placeTray(102);
    counter.placeTray(103);
    counter.placeTray(104); // Triggers full condition error
    counter.takeTray();
    counter.takeTray();
    counter.takeTray();
    counter.takeTray(); // Triggers empty condition error
    return 0;
}