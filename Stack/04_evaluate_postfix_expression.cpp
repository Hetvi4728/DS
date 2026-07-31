#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

class Stack
{
public:
    int arr[100];
    int top = -1;

    void push(int value)
    {
        if (top == 99)
        {
            cout << "Stack Overflow";
            return;
        }
        arr[++top] = value;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow";
            return -1;
        }
        return arr[top--];
    }
};

int main()
{
    char postfix[100];
    Stack s;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        // If operand, push it into stack
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        // If operator, pop two operands and perform operation
        else
        {
            int op1 = s.pop();
            int op2 = s.pop();

            switch (ch)
            {
            case '+':
                s.push(op2 + op1);
                break;

            case '-':
                s.push(op2 - op1);
                break;

            case '*':
                s.push(op2 * op1);
                break;

            case '/':
                s.push(op2 / op1);
                break;

            case '^':
                s.push((int)pow(op2, op1));
                break;

            default:
                cout << "Invalid Operator";
                return 0;
            }
        }
    }

    cout << "Result = " << s.pop();

    return 0;
}