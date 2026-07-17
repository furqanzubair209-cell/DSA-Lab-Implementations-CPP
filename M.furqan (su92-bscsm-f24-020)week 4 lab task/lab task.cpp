//             NAME: MUHAMMAD FURQAN 
//         ROLL NO: SU92-BSCSM-F24-020

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Singly Linked List class
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    // Insert a node at the front
    void InsertAtFront(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Remove node from front
    void RemoveFromFront() {
        if (head == NULL) {
            cout << "List is empty. Nothing to remove." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Display the list
    void Display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Search a value in the list
    bool SearchValue(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Value " << key << " found in the list." << endl;
                return true;
            }
            temp = temp->next;
        }
        cout << "Value " << key << " not found in the list." << endl;
        return false;
    }

    // Find total number of nodes
    int FindTotalNodes() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "Total nodes: " << count << endl;
        return count;
    }

    // Insert a node at the end
    void InsertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Remove node from end
    void RemoveFromEnd() {
        if (head == NULL) {
            cout << "List is empty. Nothing to remove." << endl;
            return;
        }

        if (head->next == NULL) { // Only one node
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // Remove a specific node
    void RemoveSpecificNode(int value) {
        if (head == NULL) {
            cout << "List is empty. Nothing to remove." << endl;
            return;
        }

        if (head->data == value) { // Value is at head
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node with value " << value << " removed." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Value " << value << " not found in the list." << endl;
        } else {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
            cout << "Node with value " << value << " removed." << endl;
        }
    }
};

// Main function
int main() {
    SinglyLinkedList list;

    list.InsertAtFront(10);
    list.InsertAtFront(20);
    list.InsertAtEnd(30);
    list.InsertAtEnd(40);

    cout << "Linked List: ";
    list.Display();

    list.SearchValue(30);
    list.SearchValue(100);

    list.FindTotalNodes();

    list.RemoveFromFront();
    cout << "After removing from front: ";
    list.Display();

    list.RemoveFromEnd();
    cout << "After removing from end: ";
    list.Display();

    list.RemoveSpecificNode(10);
    cout << "After removing specific node (10): ";
    list.Display();

    list.RemoveSpecificNode(99);

    return 0;
}

