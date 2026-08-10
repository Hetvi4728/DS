#include <iostream>
using namespace std;

int Stack[100];
int top = -1;
int size;

void push()
{
    int value;

    if (top == size - 1)
    {
        cout << "Stack is full";
    }
    else
    {
        cout << "Enter the element to push: ";
        cin >> value;

        top++;
        Stack[top] = value;

        cout << value << " pushed into the stack.";
    }
}

void peek()
{
    if (top == -1)
    {
        cout << "Stack is empty";
    }
    else
    {
        cout << "Top element is: " << Stack[top] << endl;
    }
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty";
    }
    else
    {
        cout << "Stack elements are: ";

        for (int i = top; i >= 0; i--)
        {
            cout << Stack[i] << endl;
        }
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << Stack[top] << " popped from the stack." << endl;
        top--;
    }
}

int main()
{
    cout << "Enter the size of the stack: ";
    cin >> size;

    int choice;

    do
    {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            cout << "Exiting";
            break;

        default:
            cout << "Invalid choice";
        }

    } while (choice != 5);

    return 0;
}