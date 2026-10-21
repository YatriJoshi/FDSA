#include <iostream>
using namespace std;

int main() {
    int n, q;

    cout << "Enter maximum queue capacity: ";
    cin >> n;

    cout << "Enter number of operations: ";
    cin >> q;

    int a[n];
    int front = 0;
    int rear = -1;
    int count = 0;

    while (q--) {
        string op;

        cout << "Enter operation (join id / serve): ";
        cin >> op;

        if (op == "join") {
            int id;
            cin >> id;

            if (count == n) {
                cout << "Error: Queue Full" << endl;
            }
            else {
                rear = (rear + 1) % n;
                a[rear] = id;
                count++;

                cout << "Current Front Token: " << a[front] << endl;
            }
        }
        else if (op == "serve") {
            if (count == 0) {
                cout << "Error: Queue Empty" << endl;
            }
            else {
                front = (front + 1) % n;
                count--;

                if (count == 0) {
                    front = 0;
                    rear = -1;
                    cout << "Queue Empty" << endl;
                }
                else {
                    cout << "Current Front Token: " << a[front] << endl;
                }
            }
        }
        else {
            cout << "Invalid Operation" << endl;
        }
    }

    return 0;
}