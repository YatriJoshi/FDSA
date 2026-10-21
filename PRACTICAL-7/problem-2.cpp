#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;

    Node(int x) {
        id = x;
        next = NULL;
    }
};

int main() {
    int q;

    cout << "Enter number of operations: ";
    cin >> q;

    Node* front = NULL;
    Node* rear = NULL;

    while (q--) {
        string op;

        cout << "Enter operation (arrive id / attend): ";
        cin >> op;

        if (op == "arrive") {
            int id;
            cin >> id;

            Node* newNode = new Node(id);

            if (front == NULL) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }

            cout << "Current Front Patient: " << front->id << endl;
        }
        else if (op == "attend") {
            if (front == NULL) {
                cout << "Error: Queue Empty" << endl;
            } else {
                Node* temp = front;
                front = front->next;
                delete temp;

                if (front == NULL) {
                    rear = NULL;
                    cout << "Queue Empty" << endl;
                } else {
                    cout << "Current Front Patient: " << front->id << endl;
                }
            }
        }
        else {
            cout << "Invalid Operation" << endl;
        }
    }

    return 0;
}