#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class Stack
{
public:
    char arr[100];
    int top = -1;

    void push(char ch)
    {
        arr[++top] = ch;
    }

    char pop()
    {
        if (top == -1)
            return '\0';
        return arr[top--];
    }

    char peek()
    {
        if (top == -1)
            return '\0';
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    Stack s;
    int j = 0;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix[j++] = s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch))
            {
                postfix[j++] = s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty())
    {
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0';

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
