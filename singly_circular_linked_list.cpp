#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};

node *first = NULL;

void insert_first(int value)
{
    node *new_node = new node;
    new_node->info = value;

    if (first == NULL)
    {
        first = new_node;
        new_node->next = first;
    }
    else
    {
        node *temp = first;

        while (temp->next != first)
        {
            temp = temp->next;
        }

        new_node->next = first;
        temp->next = new_node;
        first = new_node;
    }
}

void insert_last(int value)
{
    node *new_node = new node;
    new_node->info = value;

    if (first == NULL)
    {
        first = new_node;
        new_node->next = first;
    }
    else
    {
        node *temp = first;

        while (temp->next != first)
        {
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->next = first;
    }
}

void insert_after(int value, int position)
{
    node *new_node = new node;
    new_node->info = value;

    if (first == NULL)
    {
        first = new_node;
        new_node->next = first;
        return;
    }

    node *temp = first;

    do
    {
        if (temp->info == position)
        {
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
    } while (temp != first);

    cout << "Position not found." << endl;
    delete new_node;
}

void delete_first()
{
    if (first == NULL)
    {
        cout << "List is Empty" << endl;
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

        node *temp = first;

        while (temp->next != first)
        {
            temp = temp->next;
        }

        node *to_delete = first;
        first = first->next;
        temp->next = first;
        delete to_delete;
    }
}

void delete_last()
{
    node *temp = first;

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

        while (temp->next->next != first)
        {
            temp = temp->next;
        }

        node *last_node = temp->next;
        temp->next = first;
        delete last_node;
    }
}

void delete_node(int pos)
{
    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    else
    {
        node *temp = first;

        if (pos == first->info)
        {
            delete_first();
        }
        else
        {
            while (temp->next != first && temp->next->info != pos)
            {
                temp = temp->next;
            }

            if (temp->next == first)
            {
                cout << "Node not found." << endl;
            }
            else
            {
                node *to_delete = temp->next;
                temp->next = temp->next->next;
                delete to_delete;
            }
        }
    }
}

void display()
{
    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    node *temp = first;

    do
    {
        cout << temp->info << " ";
        temp = temp->next;
    } while (temp != first);

    cout << endl;
    cout << endl;
}

int main()
{
    int choice, value, position;

    while (choice != 8)
    {
        cout << " Enter your choice: " << endl;
        cout << "1. Insert at first\n 2. Insert at last\n 3. Insert after a position\n 4. Delete first\n 5. Delete last\n 6. Delete a node\n 7. Display\n 8. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at first: ";
            cin >> value;
            insert_first(value);
            cout << endl;
            break;
        case 2:
            cout << "Enter value to insert at last: ";
            cin >> value;
            insert_last(value);
            cout << endl;
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position after which to insert: ";
            cin >> position;
            insert_after(value, position);
            cout << endl;
            break;
        case 4:
            delete_first();
            cout << endl;
            break;
        case 5:
            delete_last();
            cout << endl;
            break;
        case 6:
            cout << "Enter value of node to delete: ";
            cin >> value;
            delete_node(value);
            cout << endl;
            break;
        case 7:
            display();
            break;
        case 8:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}