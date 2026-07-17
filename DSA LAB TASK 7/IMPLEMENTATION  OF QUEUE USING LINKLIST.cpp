//             NAME: MUHAMMAD FURQAN ROLL NO: SU92-BSCSM-F24-020
//             TASK 2: QUEUE IMPLEMENTATION USING LINKLIST
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class QueueLinkedList {
private:
    Node* front;
    Node* rear;

public:
    // 1. Initialize the Queue
    QueueLinkedList() {
        front = NULL;
        rear = NULL;
        cout << "Queue initialized using linked list" << endl;
    }

    // 2. Create isEmpty Function
    bool isEmpty() {
        return front == NULL;
    }

    // 3. Create Enqueue Function
    void enqueue(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " added to queue" << endl;
    }

    // 4. Create Dequeue Function
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue" << endl;
            return -1;
        }
        
        Node* temp = front;
        int value = front->data;
        front = front->next;
        
        if (front == NULL) {
            rear = NULL;
        }
        
        delete temp;
        cout << value << " removed from queue" << endl;
        return value;
    }

    // 5. Create display Function
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        cout << "Queue elements (front to rear): ";
        Node* current = front;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // 6. Create search Function
    void search(int value) {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        Node* current = front;
        int position = 1;
        bool found = false;
        
        while (current != NULL) {
            if (current->data == value) {
                cout << "Element " << value << " found at position " << position << " from front" << endl;
                found = true;
            }
            current = current->next;
            position++;
        }
        
        if (!found) {
            cout << "Element " << value << " not found in queue" << endl;
        }
    }

    // Get front element without removing
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return rear->data;
    }

    // Destructor to free memory
    ~QueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// Main function for Linked List Implementation
int main() {
    cout << "=== QUEUE IMPLEMENTATION USING LINKED LIST ===" << endl;
    QueueLinkedList q;
    
    int choice, value;
    
    do {
        cout << "\n=== Menu ===" << endl;
        cout << "1. Enqueue (Add element)" << endl;
        cout << "2. Dequeue (Remove element)" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Search Element" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Get Front Element" << endl;
        cout << "7. Get Rear Element" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
                
            case 2:
                q.dequeue();
                break;
                
            case 3:
                q.display();
                break;
                
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                q.search(value);
                break;
                
            case 5:
                if (q.isEmpty()) {
                    cout << "Queue is empty" << endl;
                } else {
                    cout << "Queue is not empty" << endl;
                }
                break;
                
            case 6:
                value = q.getFront();
                if (value != -1) {
                    cout << "Front element: " << value << endl;
                }
                break;
                
            case 7:
                value = q.getRear();
                if (value != -1) {
                    cout << "Rear element: " << value << endl;
                }
                break;
                
            case 8:
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);
    
    return 0;
}


