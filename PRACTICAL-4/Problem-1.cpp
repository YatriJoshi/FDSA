#include <iostream>
using namespace std;

struct Node {
    int token;
    Node* next;
    Node(int val) : token(val), next(nullptr) {}
};

class PatientQueue {
private:
    Node* head;

public:
    PatientQueue() : head(nullptr) {}

    // Print full queue front to back
    void printQueue() {
        if (head == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->token << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Insert at Front (Critical Patient)
    void insertFront(int token) {
        Node* newNode = new Node(token);
        newNode->next = head;
        head = newNode;
        cout << "After inserting " << token << " at front: ";
        printQueue();
    }

    // Insert at End (Routine Patient)
    void insertEnd(int token) {
        Node* newNode = new Node(token);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "After inserting " << token << " at end: ";
        printQueue();
    }

    // Insert at Specific Position (1-based index)
    void insertAtPosition(int token, int pos) {
        if (pos <= 1 || head == nullptr) {
            insertFront(token);
            return;
        }
        
        Node* temp = head;
        // Traverse to position - 1 or until the end of the list
        for (int i = 1; i < pos - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        
        Node* newNode = new Node(token);
        newNode->next = temp->next;
        temp->next = newNode;
        
        cout << "After inserting " << token << " at position " << pos << ": ";
        printQueue();
    }
};

int main() {
    PatientQueue q;
    
    // Demonstrating operations
    q.insertEnd(101);       // Routine
    q.insertEnd(102);       // Routine
    q.insertFront(99);      // Critical
    q.insertAtPosition(105, 2); // Specific position
    q.insertAtPosition(200, 10); // Out of bounds test (appends to end)

    return 0;
}