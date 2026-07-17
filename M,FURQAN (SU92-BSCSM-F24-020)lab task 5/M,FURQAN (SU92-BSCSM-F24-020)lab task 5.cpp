#include <iostream>
using namespace std;
// Node for Doubly Linked List
struct Node {
    int bookID;
    Node* prev;
    Node* next;
    // Constructor with simple assignments
    Node(int id) {
        bookID = id;
        prev = NULL;
        next = NULL;
    }
};
// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    // Constructor
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    // Insert at front
    void InsertAtFront(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) { // empty list
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << value << " at front.\n";
    }
    // Remove from front
    void RemoveFromFront() {
        if (head == NULL) {
            cout << "List is empty. Nothing to remove from front.\n";
            return;
        }
        Node* temp = head;
        cout << "Removed " << temp->bookID << " from front.\n";

        if (head == tail) { // single node
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }
    // Insert at tail
    void InsertAtTail(int value) {
        Node* newNode = new Node(value);
        if (tail == NULL) { // empty list
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Inserted " << value << " at tail.\n";
    }
    // Remove from tail
    void RemoveFromTail() {
        if (tail == NULL) {
            cout << "List is empty. Nothing to remove from tail.\n";
            return;
        }
        Node* temp = tail;
        cout << "Removed " << temp->bookID << " from tail.\n";

        if (head == tail) { // single node
            head = NULL;
            tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
    }
    // Display from front to tail
    void Display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Books (front -> tail): ";
        Node* current = head;
        while (current != NULL) {
            cout << current->bookID;
            if (current->next != NULL) cout << " -> ";
            current = current->next;
        }
        cout << "\n";
    }
    // Display reverse from tail to front
    void Display_Reverse() {
        if (tail == NULL) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Books (tail -> front): ";
        Node* current = tail;
        while (current != NULL) {
            cout << current->bookID;
            if (current->prev != NULL) cout << " -> ";
            current = current->prev;
        }
        cout << "\n";
    }
    // Search for a value
    bool SearchValue(int key) {
        Node* current = head;
        while (current != NULL) {
            if (current->bookID == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    // Remove specific value (first occurrence)
    void RemoveSpecificValue(int value) {
        if (head == NULL) {
            cout << "List is empty. Nothing to remove.\n";
            return;
        }
        Node* current = head;
        while (current != NULL && current->bookID != value) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Value " << value << " not found in the list.\n";
            return;
        }
        // If it's the only node
        if (head == tail && current == head) {
            head = NULL;
            tail = NULL;
        }
        // If deleting head
        else if (current == head) {
            head = head->next;
            head->prev = NULL;
        }
        // If deleting tail
        else if (current == tail) {
            tail = tail->prev;
            tail->next = NULL;
        }
        // Middle node
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        cout << "Removed " << value << " from the list.\n";
        delete current;
    }
    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};
// Simple menu to test the list
int main() {
    DoublyLinkedList dll;
    int choice, value;

    do {
        cout << "\n===== Library Book Tracking (Doubly Linked List) =====\n";
        cout << "1. InsertAtFront (add book at front)\n";
        cout << "2. RemoveFromFront (remove book from front)\n";
        cout << "3. InsertAtTail (add book at tail)\n";
        cout << "4. RemoveFromTail (remove book from tail)\n";
        cout << "5. Display (front -> tail)\n";
        cout << "6. Display_Reverse (tail -> front)\n";
        cout << "7. SearchValue (check book ID)\n";
        cout << "8. RemoveSpecificValue (remove specific book ID)\n";
        cout << "9. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book ID to insert at front: ";
                cin >> value;
                dll.InsertAtFront(value);
                break;
            case 2:
                dll.RemoveFromFront();
                break;
            case 3:
                cout << "Enter book ID to insert at tail: ";
                cin >> value;
                dll.InsertAtTail(value);
                break;
            case 4:
                dll.RemoveFromTail();
                break;
            case 5:
                dll.Display();
                break;
            case 6:
                dll.Display_Reverse();
                break;
            case 7:
                cout << "Enter book ID to search: ";
                cin >> value;
                if (dll.SearchValue(value)) {
                    cout << "Book ID " << value << " is available in the library.\n";
                } else {
                    cout << "Book ID " << value << " is NOT available.\n";
                }
                break;
            case 8:
                cout << "Enter book ID to remove: ";
                cin >> value;
                dll.RemoveSpecificValue(value);
                break;
            case 9:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
