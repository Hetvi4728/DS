#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *first = NULL;

struct node *create_node(int x)
{
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

void insert_first(int x)
{
    struct node *temp;

    temp = create_node(x);

    if (first == NULL)
    {
        first = temp;
        first->next = first;
        first->prev = first;
    }
    else
    {
        temp->next = first;
        temp->prev = first->prev;
        first->prev->next = temp;
        first->prev = temp;
        first = temp;
    }
}

void insert_last(int x)
{
    struct node *temp;

    temp = create_node(x);

    if (first == NULL)
    {
        first = temp;
        first->next = first;
        first->prev = first;
    }
    else
    {
        temp->next = first;
        temp->prev = first->prev;
        first->prev->next = temp;
        first->prev = temp;
    }
}

void insert_at_position(int x, int pos)
{
    struct node *temp, *new_node;
    int i;

    new_node = create_node(x);

    if (first == NULL)
    {
        first = new_node;
        first->next = first;
        first->prev = first;
    }
    else
    {
        temp = first;

        for (i = 1; i < pos - 1 && temp->next != first; i++)
        {
            temp = temp->next;
        }

        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next->prev = new_node;
        temp->next = new_node;
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
    else
    {
        if (first->next == first)
        {
            delete first;
            first = NULL;
            return;
        }

        temp = first;

        first->prev->next = first->next;
        first->next->prev = first->prev;
        first = first->next;

        delete temp;
    }
}

void delete_last()
{
    struct node *temp;

    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    else
    {
        if (first->next == first)
        {
            delete first;
            first = NULL;
            return;
        }

        temp = first->prev;

        temp->prev->next = first;
        first->prev = temp->prev;

        delete temp;
    }
}

void delete_at_position(int pos)
{
    struct node *temp;

    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    else
    {
        temp = first;

        for (int i = 1; i < pos && temp->next != first; i++)
        {
            temp = temp->next;
        }

        if (temp == first && pos == 1)
        {
            delete_first();
        }
        else if (temp->next == first && pos > 1)
        {
            delete_last();
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            delete temp;
        }
    }
}

int min()
{
    int min_value = first->data;
    struct node *temp = first->next;
    while (temp != first)
    {
        if (temp->data < min_value)
        {
            min_value = temp->data;
        }
        temp = temp->next;
    }
    return min_value;
}

int max()
{
    int max_value = first->data;
    struct node *temp = first->next;
    while (temp != first)
    {
        if (temp->data > max_value)
        {
            max_value = temp->data;
        }
        temp = temp->next;
    }
    return max_value;
}

void display()
{
    struct node *temp;

    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    temp = first;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != first);

    cout << endl;
}

void display_reverse()
{
    struct node *temp;

    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    temp = first->prev;

    do
    {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != first->prev);

    cout << endl;
}

int main()
{
    int choice, value, position;

    while (choice != 0)
    {
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Delete from beginning" << endl;
        cout << "5. Delete from end" << endl;
        cout << "6. Delete from position" << endl;
        cout << "7. Display list" << endl;
        cout << "8. Display list in reverse" << endl;
        cout << "9. Find minimum value" << endl;
        cout << "10. Find maximum value" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insert_first(value);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            insert_last(value);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position to insert at: ";
            cin >> position;
            insert_at_position(value, position);
            break;
        case 4:
            delete_first();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            cout << "Enter position to delete from: ";
            cin >> position;
            delete_at_position(position);
            break;
        case 7:
            display();
            break;
        case 8:
            display_reverse();
            break;
        case 9:
            cout << "Minimum value in the list: " << min() << endl;
            break;
        case 10:
            cout << "Maximum value in the list: " << max() << endl;
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}