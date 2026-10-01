#include <iostream>
#include <string>

using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;
    Node(string s) : song(s), prev(nullptr), next(nullptr) {}
};

class Playlist {
private:
    Node* head;
    Node* tail;

public:
    Playlist() : head(nullptr), tail(nullptr) {}

    int count() {
        int cnt = 0;
        Node* curr = head;
        while (curr) {
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }

    void display() {
        cout << "    Playlist (" << count() << " songs): ";
        if (!head) {
            cout << "Empty\n\n";
            return;
        }
        Node* curr = head;
        while (curr) {
            cout << curr->song;
            if (curr->next) cout << " <-> ";
            curr = curr->next;
        }
        cout << "\n\n";
    }

    void addBeginning(string song) {
        Node* newNode = new Node(song);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "[+] Added '" << song << "' to beginning\n";
        display();
    }

    void addEnd(string song) {
        Node* newNode = new Node(song);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "[+] Added '" << song << "' to end\n";
        display();
    }

    void insertAfter(string targetSong, string song) {
        Node* curr = head;
        while (curr) {
            if (curr->song == targetSong) {
                Node* newNode = new Node(song);
                newNode->next = curr->next;
                newNode->prev = curr;
                if (curr->next) {
                    curr->next->prev = newNode;
                } else {
                    tail = newNode;
                }
                curr->next = newNode;
                cout << "[+] Inserted '" << song << "' after '" << targetSong << "'\n";
                display();
                return;
            }
            curr = curr->next;
        }
        cout << "[!] Target song '" << targetSong << "' not found in playlist.\n\n";
    }

    void removeFirst() {
        if (!head) {
            cout << "[!] Playlist is empty.\n";
            return;
        }
        Node* temp = head;
        string removed = temp->song;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        cout << "[-] Removed first song: '" << removed << "'\n";
        display();
    }
};

int main() {
    Playlist pl;
    pl.addEnd("Song A");
    pl.addEnd("Song B");
    pl.addBeginning("Song C");
    pl.insertAfter("Song A", "Song D");
    pl.insertAfter("Unknown Song", "Song X"); // Target not found case
    pl.removeFirst();
    pl.removeFirst();
    return 0;
}