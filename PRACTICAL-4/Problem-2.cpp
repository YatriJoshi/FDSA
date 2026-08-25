#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int token;
    Node* next;
    Node(int val) : token(val), next(nullptr) {}
};

class PatientQueue {
private:
    Node* head;

    // Helper method for recursive reverse printing
    void printReverseRecursive(Node* node) {
        if (node == nullptr) return;
        printReverseRecursive(node->next);
        cout << node->token << " ";
    }

public:
    PatientQueue() : head(nullptr) {}

    void insertEnd(int token) {
        Node* newNode = new Node(token);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Forward Traversal (Front to Back)
    void displayForward() {
        cout << "Queue (Front to Back): ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->token << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Delete a patient token by value
    void deleteByValue(int token) {
        if (head == nullptr) return;

        // If head node holds the key to be deleted
        if (head->token == token) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted token " << token << endl;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->token != token) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Deleted token " << token << endl;
        } else {
            cout << "Token " << token << " not found." << endl;
        }
    }

    // Reverse Printing using Recursion (No structure modification)
    void displayReverseRecursive() {
        cout << "End-of-day Audit (Back to Front - Recursive): ";
        printReverseRecursive(head);
        cout << endl;
    }

    // Alternative Reverse Printing using an Explicit Stack (No structure modification)
    void displayReverseStack() {
        cout << "End-of-day Audit (Back to Front - Stack): ";
        stack<int> s;
        Node* temp = head;
        while (temp != nullptr) {
            s.push(temp->token);
            temp = temp->next;
        }
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

int main() {
    PatientQueue q;

    // Setup initial queue
    q.insertEnd(101);
    q.insertEnd(102);
    q.insertEnd(103);
    q.insertEnd(104);

    q.displayForward();
    
    // Reverse print tests
    q.displayReverseRecursive();
    q.displayReverseStack();

    // Deletion test
    q.deleteByValue(102);
    q.displayForward();

    return 0;
}