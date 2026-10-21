#include <iostream>
#include <string>
using namespace std;

struct Node {
    string page;
    Node* next;
};

class BrowserHistory {
private:
    Node* top;

public:
    BrowserHistory() {
        top = nullptr;
    }

    ~BrowserHistory() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void visit(string url) {
        Node* newNode = new Node();
        newNode->page = url;
        newNode->next = top;
        top = newNode;
        cout << "Visited: " << url << " | Current Page: " << top->page << "\n";
    }

    void back() {
        if (isEmpty()) {
            cout << "Error: No history left! You are on the very first page.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        
        if (isEmpty()) {
            cout << "Pressed Back. No previous pages left (at the start page).\n";
        } else {
            cout << "Pressed Back. Current Page: " << top->page << "\n";
        }
    }
};

int main() {
    BrowserHistory browser;
    browser.visit("google.com");
    browser.visit("github.com");
    browser.visit("stackoverflow.com");
    browser.back();
    browser.back();
    browser.back();
    browser.back(); // Triggers no history left error
    return 0;
}