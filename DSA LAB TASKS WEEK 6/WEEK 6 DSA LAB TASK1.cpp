
//             NAME: MUHAMMAD FURQAN ROLL NO: SU92-BSCSM-F24-020
//             LAB TASK 1
//             IMPLEMENTING STACK USING ARRAY
#include <iostream>
using namespace std;
class Stack
 {
private:
    int* arr;
    int top;
    int maxSize;
public:
    Stack(int size) 
	{
        maxSize = size;
        arr = new int[maxSize];
        top = -1;
    }
    bool isEmpty()
	 {
        return (top == -1);
    }
    bool isFull()
	 {
        return (top == maxSize - 1);
    }
    void push(int value)
	 {
        if (isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }
        arr[++top] = value;
    }
    int pop()
	 {
        if (isEmpty())
		 {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top--];
    }
    void display()
	 {
        if (isEmpty())
		 {
            cout << "Stack is empty!" << endl;
            return;
        }
        for (int i = 0; i <= top; i++) 
		{
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int search(int value)
	 {
        for (int i = 0; i <= top; i++) 
		{
            if (arr[i] == value) 
			{
                return i;
            }
        }
        return -1;
    }
    ~Stack()
	 {
        delete[] arr;
    }
};
int main()
 {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(25);
    s.display();
    cout << "Popped: " << s.pop() << endl;
    s.display();
    cout << "Search 20: " << s.search(20) << endl;
    return 0;
}
