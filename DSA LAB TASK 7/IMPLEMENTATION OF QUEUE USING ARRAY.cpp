//             NAME: MUHAMMAD FURQAN ROLL NO: SU92-BSCSM-F24-020
//             LAB TASK 1 
//             TASK 1: QUEUE IMPLEMENTATION USING ARRAY
#include <iostream>
using namespace std;
class QueueArray {
private:
    int *arr;
    int front, rear;
    int capacity;
    int size;
public:
    // 1. Initialize the Queue
    QueueArray(int maxSize) {
        capacity = maxSize;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
        cout << "Queue initialized with capacity " << capacity << endl;
    }

    // 2. Create isEmpty Function
    bool isEmpty() {
        return size == 0;
    }

    // 3. Create isFull Function
    bool isFull() {
        return size == capacity;
    }

    // 4. Create Enqueue Function
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot add " << value << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << value << " added to queue" << endl;
    }

    // 5. Create Dequeue Function
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue" << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        cout << value << " removed from queue" << endl;
        return value;
    }

    // 6. Create display Function
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements (front to rear): ";
        int count = 0;
        int index = front;
        while (count < size) {
            cout << arr[index] << " ";
            index = (index + 1) % capacity;
            count++;
        }
        cout << endl;
        cout << "Front: " << front << ", Rear: " << rear << ", Size: " << size << endl;
    }

    // 7. Create search Function
    void search(int value) {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        int count = 0;
        int index = front;
        int position = 1;
        bool found = false;
        
        while (count < size) {
            if (arr[index] == value) {
                cout << "Element " << value << " found at position " << position << " from front" << endl;
                found = true;
            }
            index = (index + 1) % capacity;
            count++;
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
        return arr[front];
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }
};

// Main function for Array Implementation
int main() {
    cout << "=== QUEUE IMPLEMENTATION USING ARRAYS ===" << endl;
    cout << "Creating a queue with capacity 5" << endl;
    QueueArray q(5);
    
    int choice, value;
    
    do {
        cout << "\n=== Menu ===" << endl;
        cout << "1. Enqueue (Add element)" << endl;
        cout << "2. Dequeue (Remove element)" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Search Element" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "7. Get Front Element" << endl;
        cout << "8. Get Rear Element" << endl;
        cout << "9. Exit" << endl;
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
                if (q.isFull()) {
                    cout << "Queue is full" << endl;
                } else {
                    cout << "Queue is not full" << endl;
                }
                break;
                
            case 7:
                value = q.getFront();
                if (value != -1) {
                    cout << "Front element: " << value << endl;
                }
                break;
                
            case 8:
                value = q.getRear();
                if (value != -1) {
                    cout << "Rear element: " << value << endl;
                }
                break;
                
            case 9:
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 9);
    
    return 0;
}

