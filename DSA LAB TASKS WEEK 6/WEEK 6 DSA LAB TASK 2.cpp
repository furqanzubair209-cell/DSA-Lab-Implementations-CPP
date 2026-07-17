
//             NAME: MUHAMMAD FURQAN ROLL NO: SU92-BSCSM-F24-020
//             LAB TASK 2
//             IMPLEMENTING STACK USING LINKLIST
#include <iostream>
using namespace std;
class Node
 {
public:
    int data;
    Node* next;
    Node(int value)
	 {
        data = value;
        next = NULL;
    }
};
class Stack
 {
private:
    Node* top;

public:
    Stack()
	 {
        top = NULL;
    }
    bool isEmpty()
	 {
        return (top == NULL);
    }
    void push(int value) 
	{
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    int pop() {
        if (isEmpty()) 
		{
            cout << "Stack is empty!" << endl;
            return -1;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }
    void display() 
	{
        if (isEmpty())
		 {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        while (temp != NULL)
		 {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int search(int value)
	 {
        Node* temp = top;
        int position = 0;
        while (temp != NULL) 
		{
            if (temp->data == value)
			 {
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1;
    }
    ~Stack()
	 {
        while (!isEmpty())
		 {
            pop();
        }
    }
};
int main() 
{
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.display();
    cout << "Popped: " << s.pop() << endl;
    s.display();
    cout << "Search 10: " << s.search(10) << endl;
    return 0;
}
