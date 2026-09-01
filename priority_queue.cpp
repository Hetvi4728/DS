#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX];
int priority[MAX];
int n = 0;

void insert()
{
    int x, p, i;

    if (n == MAX)
    {
        cout << "Priority Queue is full\n";
        return;
    }

    cout << "Enter value: ";
    cin >> x;

    cout << "Enter priority: ";
    cin >> p;

    i = n - 1;

    while (i >= 0 && priority[i] > p)
    {
        arr[i + 1] = arr[i];
        priority[i + 1] = priority[i];
        i--;
    }

    arr[i + 1] = x;
    priority[i + 1] = p;
    n++;
}

void deleteElement()
{
    if (n == 0)
    {
        cout << "Priority Queue is empty\n";
        return;
    }

    cout << "Deleted element: " << arr[0] << endl;

    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
        priority[i] = priority[i + 1];
    }

    n--;
}

void display()
{
    if (n == 0)
    {
        cout << "Priority Queue is empty\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int choice;

    while (1)
    {
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            deleteElement();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}