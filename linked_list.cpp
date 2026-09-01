#include <iostream>
using namespace std;

struct node *first = NULL;

struct node
{
    int data;
    struct node *next;
};

struct node *create_node(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->data = x;
    temp->next = NULL;

    return temp;
}

void insert_first(int x)
{
    struct node *t;
    t = create_node(x);

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        t->next = first;
        first = t;
    }
}

void insert_last(int x)
{
    struct node *t, *temp;
    t = create_node(x);

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = t;
    }
}

void insert_at_position(int x, int pos)
{
    struct node *t, *temp;
    t = create_node(x);

    if (pos == 1)
    {
        t->next = first;
        first = t;
    }
    else
    {
        temp = first;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            t->next = temp->next;
            temp->next = t;
        }
        else
        {
            cout << "Position out of bounds." << endl;
            free(t);
        }
    }
}

void delete_first()
{
    struct node *temp;

    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    temp = first;
    first = first->next;
    free(temp);
}

void delete_last()
{
    struct node *temp, *prev;

    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (first->next == NULL)
    {
        free(first);
        first = NULL;
        return;
    }

    temp = first;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void delete_at_position(int pos)
{
    struct node *temp, *prev;

    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (pos == 1)
    {
        temp = first;
        first = first->next;
        free(temp);
        return;
    }

    temp = first;
    for (int i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL)
    {
        prev->next = temp->next;
        free(temp);
    }
    else
    {
        cout << "Position out of bounds." << endl;
    }
}

void display()
{
    struct node *t;
    t = first;

    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

int main()
{
    int choice;
    int n;
    int pos;

    cout << "1. insert \n2. display  \n 3.insert at last  \n 4. insert at position \n 5. delete first \n 6. delete last \n 7. delete at position \n 8. Exit \nEnter choice: ";
    cin >> choice;

    while (choice != 8)
    {
        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> n;
            insert_first(n);
        }
        else if (choice == 2)
        {
            display();
            cout << endl;
        }
        else if (choice == 3)
        {
            cout << "Enter value: ";
            cin >> n;
            insert_last(n);
        }
        else if (choice == 4)
        {
            cout << "Enter value: ";
            cin >> n;
            cout << "Enter position: ";
            cin >> pos;
            insert_at_position(n, pos);
        }
        else
        {
            cout << "Invalid choice." << endl;
            break;
        }
        cout << "\n1. insert \n2. display\n3. insert at last \n4. insert at position \n5. delete first \n6. delete last \n7. delete at position \n8. Exit \nEnter choice: ";
        cin >> choice;
    }

    return 0;
}